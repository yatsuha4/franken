/***********************************************************************//**
	@file
***************************************************************************/
#include "franken/file/fbx/Importer.hpp"

namespace franken::file::fbx {
/***********************************************************************//**
	@brief コンストラクタ
***************************************************************************/
Importer::Importer(const ContextPtr& context)
  : fk::ContextHolder<Context>(context), 
    manager_(FbxManager::Create()), 
    importer_(FbxImporter::Create(manager_, "Importer")), 
    scene_(FbxScene::Create(manager_, "Scene"))
{
}
/***********************************************************************//**
	@brief デストラクタ
***************************************************************************/
Importer::~Importer() {
  manager_->Destroy();
}
/***********************************************************************//**
	@brief 
***************************************************************************/
void Importer::importModel(const std::filesystem::path& path) {
  importer_->Initialize(path.c_str());
  importer_->Import(scene_);
  auto& settings = scene_->GetGlobalSettings();
  FbxAxisSystem(FbxAxisSystem::eOpenGL).ConvertScene(scene_);
  timeMode_ = settings.GetTimeMode();
  period_.SetTime(0, 0, 0, 1, 0, timeMode_);
  fps_ = static_cast<int>(1.0 / period_.GetSecondDouble() + 0.5);

  FbxGeometryConverter converter(manager_);
  converter.Triangulate(scene_, true);
  auto* root = scene_->GetRootNode();
}
/***********************************************************************//**
	$Id$
***************************************************************************/
}
