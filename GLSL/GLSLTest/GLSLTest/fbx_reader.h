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

	auto* const getScene(const std::string& file_name)
	{
			auto* const scene = FbxScene::Create(fbx_manager_, "");
			fbx_importer_->Initialize(file_name.c_str());
			fbx_importer_->Import(scene);

			auto fbx_geometry_converter = FbxGeometryConverter(fbx_manager_);
			fbx_geometry_converter.Triangulate(scene, true);
			fbx_geometry_converter.SplitMeshesPerMaterial(scene, true);

			return scene;
	}

private:
	fbxsdk::FbxManager* const fbx_manager_ = fbxsdk::FbxManager::Create();
	fbxsdk::FbxImporter* const fbx_importer_;
};