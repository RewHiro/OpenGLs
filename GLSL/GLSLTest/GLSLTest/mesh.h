#pragma once

struct Mesh
{
public:
	std::vector<Eigen::Vector4f> vertices = std::vector<Eigen::Vector4f>();
	std::vector<Eigen::Vector4f> normals = std::vector<Eigen::Vector4f>();
	std::vector<uint> indices = std::vector<uint>();
	uint polygon_count = 0;
	GLuint vao = 0;
};