#pragma once

class MeshRenderer
{
public:
	MeshRenderer() = default;
	explicit MeshRenderer(const std::string& file_name)
	{
		//ここでノードを作る、ノードの中にマテリアル、メッシュを作成

		auto* const scene = FBXReader()().getScene(file_name);
		auto* const node = scene->GetRootNode();

		// 再帰使用する場合は、autoは使用できないため明示的に宣言
		// キャプチャは&にしないと呼び出しに失敗する(らしい・・・試してない)
		std::function<void(FbxNode* const fbx_node, SharedNode& node, SharedNode& parent_node)> replaceMyMesh = [&](FbxNode* const fbx_node, SharedNode& node, SharedNode& parent_node)
		{
			if (fbx_node->GetParent() != nullptr)node->parent = parent_node;

			const int ATTR_COUNT = fbx_node->GetNodeAttributeCount();
			//if (ATTR_COUNT == 0)return;

			for (auto i = 0; i < 4; ++i)
			{
				for (auto j = 0; j < 4; ++j)
				{
					node->matrix.data()[i * 4 + j] = fbx_node->EvaluateGlobalTransform().mData[i].mData[j];
				}
			}

			node->name = fbx_node->GetName();

			for (auto i = 0; i < ATTR_COUNT; ++i)
			{
				auto* const attr = fbx_node->GetNodeAttributeByIndex(i);
				if (attr->GetAttributeType() != FbxNodeAttribute::eMesh)continue;

				auto* const fbx_mesh = static_cast<FbxMesh*>(attr);
				auto mesh = Mesh();

				const auto VERTEX_COUNT = fbx_mesh->GetPolygonVertexCount();
				auto* const vertex_indices = fbx_mesh->GetPolygonVertices();
				for (auto i = 0; i < VERTEX_COUNT; ++i)
				{
					auto& fbx_vector = fbx_mesh->GetControlPointAt(vertex_indices[i]);
					auto vector = Eigen::Vector4f(fbx_vector[0], fbx_vector[1], fbx_vector[2], fbx_vector[3]);
					mesh.vertices.emplace_back(vector);
					mesh.indices.emplace_back(vertex_indices[i]);
				}

				auto normals = FbxArray<FbxVector4>();
				fbx_mesh->GetPolygonVertexNormals(normals);

				for (int i = 0; i < normals.Size(); ++i)
				{
					mesh.normals.emplace_back(normals[i][0], normals[i][1], normals[i][2], normals[i][3]);
				}

				mesh.polygon_count = fbx_mesh->GetPolygonCount();

				{
					glGenVertexArrays(1, &mesh.vao);
					glBindVertexArray(mesh.vao);

					GLuint buffers[3];

					glGenBuffers(3, buffers);

					auto& vertices = mesh.vertices;
					glBindBuffer(GL_ARRAY_BUFFER, buffers[0]);
					glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Eigen::Vector4f), vertices.data(), GL_STATIC_DRAW);
					glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(Eigen::Vector4f), 0);
					glEnableVertexAttribArray(0);

					auto& normals = mesh.normals;
					glBindBuffer(GL_ARRAY_BUFFER, buffers[1]);
					glBufferData(GL_ARRAY_BUFFER, normals.size() * sizeof(Eigen::Vector4f), vertices.data(), GL_STATIC_DRAW);
					glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Eigen::Vector4f), 0);
					glEnableVertexAttribArray(0);

					auto& indices = mesh.indices;
					glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffers[2]);
					glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(uint), indices.data(), GL_STATIC_DRAW);

					glBindBuffer(GL_ARRAY_BUFFER, 0);
					glBindVertexArray(0);
				}

				node->meshes.emplace_back(mesh);
			}

			const auto CHILD_COUNT = fbx_node->GetChildCount();

			for (auto i = 0; i < CHILD_COUNT; ++i)
			{
				node->children.emplace_back(std::make_shared<Node>());
				replaceMyMesh(fbx_node->GetChild(i), node->children[i], node);
			}
		};
	}

	void update()
	{
		auto& meshes = node_->meshes;

		for (auto& mesh : meshes)
		{
			glBindVertexArray(mesh.vao);

			glDrawElements(GL_TRIANGLES, mesh.polygon_count, GL_UNSIGNED_INT, 0);

			glBindVertexArray(0);
		}
	}

private:
	SharedNode node_ = std::make_shared<Node>();
};