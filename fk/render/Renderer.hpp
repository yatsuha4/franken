/***********************************************************************//**
	@file
***************************************************************************/
#pragma once

#include "fk/framework/ContextHolder.hpp"
#include "fk/math/Rect.hpp"

namespace fk {
namespace render {
/***********************************************************************//**
	@brief レンダラー
***************************************************************************/
class Renderer
  : public ContextHolder<>
{
 public:
  enum ClearFlag {
    CLEAR_COLOR		= 1 << 0, 
    CLEAR_DEPTH		= 1 << 1, 
    CLEAR_STENCIL	= 1 << 2, 
    CLEAR_ALL		= ~0
  };

 private:
  GLint defaultFrameBuffer_;
  IRect viewport_;

 public:
  Renderer(const ContextPtr& context);
  ~Renderer();

  void beginRender(const IRect& viewport);
  void endRender();

  void setViewport(const IRect& viewport);
  FK_GETTER(Viewport, viewport_);

  void clear(ClearFlag flag = CLEAR_ALL, 
             const glm::vec4& color = glm::vec4(0));

  virtual void render(RenderablePtr renderable, const RenderParam& param);

  void checkError();
};
/***********************************************************************//**
	$Id$
***************************************************************************/
}
}
