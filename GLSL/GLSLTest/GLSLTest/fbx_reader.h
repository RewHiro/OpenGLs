#pragma once

class FBXReader : public Singleton<FBXReader>
{
public:
	FBXReader() :
		fbx_importer_(fbxsdk::FbxImporter::Create(fbx_manager_, ""))
	{
	}

	~FBXReader()
	{
		fbx_manager_->Destroy();
	}

	auto test(const char* const file_name)
	{
		auto* const scene = FbxScene::Create(fbx_manager_, "");
		fbx_importer_->Initialize(file_name);

		fbx_importer_->Import(scene);

		Mesh mesh;

		const auto fbx_mesh = scene->GetRootNode()->GetMesh();
		auto* const vertex_indices = fbx_mesh->GetPolygonVertices();
		auto vertex_size = fbx_mesh->GetPolygonVertexCount();
		for (int i = 0; i < vertex_size; ++i)
		{
			FbxVector4 fbx_vector = fbx_mesh->GetControlPointAt(vertex_indices[i]);
			Eigen::Vector4f vector = Eigen::Vector4f( fbx_vector[0],fbx_vector[1] ,fbx_vector[2] , fbx_vector[3] );
			mesh.vertices_.emplace_back(vector);
		}
	}

private:
	fbxsdk::FbxManager* const fbx_manager_ = fbxsdk::FbxManager::Create();
	fbxsdk::FbxImporter* const fbx_importer_;
};