#pragma once

struct Mesh
{
public:

		//auto mesh = FBXReader()().createMesh( file_name.c_str() );

		//glGenVertexArrays(1, &vao_);
		//glBindVertexArray(vao_);

		//GLuint buffers[3];

		//glGenBuffers(3, buffers);

		//auto vertices = mesh.GetVertices();
		//glBindBuffer(GL_ARRAY_BUFFER, buffers[0]);
		//glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Eigen::Vector4f), vertices.data(), GL_STATIC_DRAW);
		//glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(Eigen::Vector4f), 0);
		//glEnableVertexAttribArray(0);

		//auto normals = mesh.GetNormals();
		//glBindBuffer(GL_ARRAY_BUFFER, buffers[1]);
		//glBufferData(GL_ARRAY_BUFFER, normals.size() * sizeof(Eigen::Vector4f), vertices.data(), GL_STATIC_DRAW);
		//glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Eigen::Vector4f), 0);
		//glEnableVertexAttribArray(0);

		//auto indices = mesh.GetIndices();
		//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffers[2]);
		//glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(uint), indices.data(), GL_STATIC_DRAW);

		//glBindBuffer(GL_ARRAY_BUFFER, 0);
		//glBindVertexArray(0);
	std::vector<Eigen::Vector4f> vertices_;
	std::vector<Eigen::Vector4f> normals_;
	std::vector<uint> indices_;
	uint polygon_count_ = 0;
	GLuint vao_;
};