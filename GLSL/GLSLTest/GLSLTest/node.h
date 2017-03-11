#pragma once

struct Node;
using SharedNode = std::shared_ptr<Node>;
using WeakNode = std::weak_ptr<Node>;

struct Node
{
public:

	//Material
	const char* name_;
	Eigen::Matrix4f matrix_;
	std::vector<Mesh>meshes_;
	WeakNode parent_;
	std::vector<SharedNode>children_;
};