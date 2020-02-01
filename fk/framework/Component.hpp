/***********************************************************************//**
	@file
***************************************************************************/
#pragma once

#include "fk/framework/Behaviour.hpp"

namespace fk {
namespace framework {
/***********************************************************************//**
	@brief コンポーネント
***************************************************************************/
class Component
  : public Behaviour
{
  using super = Behaviour;

 private:
  std::weak_ptr<Object> object_;

 public:
  ~Component() override;

  ObjectPtr getObject() const {
    return object_.lock();
  }

 protected:
  Component(const ObjectPtr& object);
};
/***********************************************************************//**
	$Id$
***************************************************************************/
}
}
