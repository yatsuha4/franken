/***********************************************************************//**
	@file
***************************************************************************/
#pragma once

#include "fk/resource/MemoryResource.hpp"

namespace fk::resource {
/***********************************************************************//**
	@brief 
***************************************************************************/
class FileResource
  : public MemoryResource
{
 private:
  std::filesystem::path path_;

 public:
  FileResource(const std::filesystem::path& path);
  ~FileResource() override = default;

  bool read();
};
/***********************************************************************//**
	$Id$
***************************************************************************/
}
