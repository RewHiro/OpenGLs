#pragma once

struct Mesh
{
public:
	std::vector<Eigen::Vector4f> vertices_;
	std::vector<Eigen::Vector4f> normals_;
	std::vector<uint> indices_;
	uint polygon_count_ = 0;
	GLuint vao_;
};