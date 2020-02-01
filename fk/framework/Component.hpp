/***********************************************************************//**
	@file
***************************************************************************/
#pragma once

#include "fk/framework/Updatable.hpp"

namespace fk {
namespace framework {
/***********************************************************************//**
	@brief コンポーネント
***************************************************************************/
class Component
  : public Updatable
{
  using super = Updatable;

 private:
  Object& object_;

 public:
  ~Component() override;

  Object& getObject() const {
    return object_;
  }

 protected:
  Component(Object& object);
};
/***********************************************************************//**
	$Id$
***************************************************************************/
}
}
