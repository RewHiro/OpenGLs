#pragma once

struct Mesh
{
public:

	friend class FBXReader;

	std::vector<Eigen::Vector4f> GetVertices()const { return vertices_; }
	std::vector<Eigen::Vector4f> GetNormals() const { return normals_; }
	std::vector<uint> GetIndices()const { return indices_; }
	uint GetPolygonCount()const { return polygon_count_; }

private:
	std::vector<Eigen::Vector4f> vertices_;
	std::vector<Eigen::Vector4f> normals_;
	std::vector<uint> indices_;
	uint polygon_count_ = 0;
};