#pragma once

struct Node;
using SharedNode = std::shared_ptr<Node>;
using WeakNode = std::weak_ptr<Node>;

struct Node
{
public:

	//Material
	const char* name = "";
	Eigen::Matrix4f matrix = Eigen::Matrix4f::Identity();
	std::vector<Mesh>meshes = std::vector<Mesh>();
	WeakNode parent;
	std::vector<SharedNode>children = std::vector<SharedNode>();
};