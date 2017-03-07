#pragma once

struct Node
{
public:

	//Material
	Eigen::Matrix4f matrix_;
	std::vector<Mesh>meshes_;
	std::vector<std::shared_ptr<Node>>children_;
};