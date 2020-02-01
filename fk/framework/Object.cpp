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
  super::update();
  for(auto& component : getComponents()) {
    component->update();
  }
  for(auto& child : getChildren()) {
    child->update();
  }
}
/***********************************************************************//**
	@copydoc Renderable::render
***************************************************************************/
void Object::render(Renderer& renderer, const RenderParam& param) {
  super::render(renderer, param);
  for(auto& component : getComponents()) {
    component->render(renderer, param);
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
