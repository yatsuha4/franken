/***********************************************************************//**
	@file
***************************************************************************/
#include "fk/framework/Component.hpp"
#include "fk/framework/Object.hpp"

namespace fk {
namespace framework {
/***********************************************************************//**
	@brief コンストラクタ
        @param[in] context コンテキスト
***************************************************************************/
Object::Object(const ContextPtr& context)
  : ContextHolder<>(context)
{
}
/***********************************************************************//**
	@brief デストラクタ
***************************************************************************/
Object::~Object() {
}
/***********************************************************************//**
	@copydoc Updatable::update
***************************************************************************/
void Object::update() {
  Updatable::update();
  for(auto& component : components_) {
    component->update();
  }
  for(auto& child : children_) {
    child->update();
  }
}
/***********************************************************************//**
	@copydoc Renderable::render
***************************************************************************/
void Object::render(Renderer& renderer, const RenderParam& param) {
  Renderable::render(renderer, param);
  for(auto& component : getComponents()) {
    if(auto renderable = std::dynamic_pointer_cast<Renderable>(component)) {
      renderable->render(renderer, param);
    }
  }
  for(auto& child : getChildren()) {
    child->render(renderer, param);
  }
}
/***********************************************************************//**
	$Id$
***************************************************************************/
}
}
