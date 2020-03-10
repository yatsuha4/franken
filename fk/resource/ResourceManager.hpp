/***********************************************************************//**
	@file
***************************************************************************/
#pragma once

#include "fk/framework/Behaviour.hpp"
#include "fk/resource/Resource.hpp"

namespace fk::resource {
/***********************************************************************//**
	@brief 
***************************************************************************/
class ResourceManager
  : public Behaviour, 
    public Resource
{
 private:
  std::vector<ResourcePtr> resources_;

 public:
  ResourceManager() = default;
  ~ResourceManager() override = default;

  size_t getSize() const override;
};
/***********************************************************************//**
	$Id$
***************************************************************************/
}
