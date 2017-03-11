#pragma once

struct Node;
using SharedNode = std::shared_ptr<Node>;

struct Node
{
public:

	//Material
	Eigen::Matrix4f matrix_;
	std::vector<Mesh>meshes_;
	SharedNode parent_;
	std::vector<SharedNode>children_;
};