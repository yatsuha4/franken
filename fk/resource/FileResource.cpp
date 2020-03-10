/***********************************************************************//**
	@file
***************************************************************************/
#include "fk/resource/FileResource.hpp"

namespace fk::resource {
/***********************************************************************//**
	@brief コンストラクタ
***************************************************************************/
FileResource::FileResource(const std::filesystem::path& path)
  : path_(path)
{
}
/***********************************************************************//**
	@brief 
***************************************************************************/
bool FileResource::read() {
  setReady(false);
  std::error_code error;
  auto size = std::filesystem::file_size(path_, error);
  if(!error) {
    std::ifstream stream(path_, std::ios::binary);
    if(!stream.fail()) {
      auto data = allocate(size);
      if(!stream.read(static_cast<char*>(data), size).fail()) {
        setReady();
        return true;
      }
    }
  }
  clear();
  return false;
}
/***********************************************************************//**
	$Id$
***************************************************************************/
}
