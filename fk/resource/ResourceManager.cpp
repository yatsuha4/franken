﻿/***********************************************************************//**
	@file
***************************************************************************/
#include "fk/resource/ResourceManager.hpp"

namespace fk::resource {
/***********************************************************************//**
	@brief 
***************************************************************************/
size_t ResourceManager::getSize() const {
  size_t size = 0;
  for(auto& resource : resources_) {
    size += resource->getSize();
  }
  return size;
}
/***********************************************************************//**
	$Id$
***************************************************************************/
}
