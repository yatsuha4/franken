/***********************************************************************//**
	@file
***************************************************************************/
#pragma once

namespace franken::file::fbx {
/***********************************************************************//**
	@brief 
***************************************************************************/
class Importer
  : fk::ContextHolder<Context>
{
 private:
  FbxManager* manager_;
  FbxImporter* importer_;
  FbxScene* scene_;
  FbxTime::EMode timeMode_;
  FbxTime period_;
  int fps_;
  FbxStringList uvSetNames_;
  std::vector<fk::Vertex> vertexes_;

 public:
  Importer(const ContextPtr& context);
  ~Importer();

  void importModel(const std::filesystem::path& path);
};
/***********************************************************************//**
	$Id$
***************************************************************************/
}
