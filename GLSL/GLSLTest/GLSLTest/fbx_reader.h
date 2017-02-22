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

	auto test()
	{
		FbxScene* const scene = FbxScene::Create(fbx_manager_, "");
		const char* const file_name = "";
		fbx_importer_->Initialize(file_name);

		fbx_importer_->Import(scene);

		scene->GetRootNode()->GetMesh();
	}

private:
	fbxsdk::FbxManager* const fbx_manager_ = fbxsdk::FbxManager::Create();
	fbxsdk::FbxImporter* const fbx_importer_;
};