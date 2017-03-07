#pragma once

class MeshRenderer
{
public:
	MeshRenderer() = default;
	explicit MeshRenderer(const std::string& file_name)
	{
		//ここでノードを作る、ノードの中にマテリアル、メッシュを作成
	}

	void update()
	{

	}

private:
	Node node_;
};