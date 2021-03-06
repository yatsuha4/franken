﻿/***********************************************************************//**
	@file
***************************************************************************/
#pragma once

namespace fk {
namespace render {
/***********************************************************************//**
	@brief 描画できるもの
***************************************************************************/
class Renderable {
 public:
  Renderable() = default;
  virtual ~Renderable() = default;

  virtual void render(Renderer& renderer, const RenderParam& param);

 protected:
  virtual void onRender(Renderer& renderer, const RenderParam& param) {}
};
/***********************************************************************//**
	$Id$
***************************************************************************/
}
}
