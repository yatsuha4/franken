/***********************************************************************//**
	@file
***************************************************************************/
#pragma once

#include "fk/framework/ContextHolder.hpp"
#include "fk/framework/Behaviour.hpp"

namespace fk {
namespace framework {
/***********************************************************************//**
	@brief 
***************************************************************************/
class Object
  : public Behaviour, 
    public std::enable_shared_from_this<Object>, 
    public ContextHolder<>
{
  using super = Behaviour;

 private:
  std::vector<ComponentPtr> components_;
  std::vector<ObjectPtr> children_;

 public:
  Object(const ContextPtr& context);
  ~Object() override;

  FK_REFER(Components, components_);
  FK_REFER(Children, children_);

  template <class T, class... Args>
  std::shared_ptr<T> appendComponent(Args... args) {
    auto component = std::make_shared<T>(*this, args...);
    getComponents().push_back(component);
    return component;
  }

  void update() override;
  void render(Renderer& renderer, const RenderParam& param) override;
};
/***********************************************************************//**
	$Id$
***************************************************************************/
}
}
