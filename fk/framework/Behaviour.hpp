/***********************************************************************//**
	@file
***************************************************************************/
#pragma once

namespace fk {
namespace framework {
/***********************************************************************//**
	@brief 動作するもの
***************************************************************************/
class Behaviour {
 public:
  Behaviour() = default;
  virtual ~Behaviour() = default;

  virtual void update();
  virtual void render(Renderer& renderer, const RenderParam& param);

 protected:
  virtual void onUpdate() {}
  virtual void onRender(Renderer& renderer, const RenderParam& param) {}
};
/***********************************************************************//**
	$Id$
***************************************************************************/
}
}
