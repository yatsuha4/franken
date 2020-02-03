﻿/***********************************************************************//**
	@file
***************************************************************************/
#include "fk/render/Renderable.hpp"

namespace fk {
namespace render {
/***********************************************************************//**
	@brief 描画リクエスト
	@param[in] renderer レンダラー
	@param[in] param 描画パラメーター
***************************************************************************/
void Renderable::render(Renderer& renderer, const RenderParam& param) {
  onRender(renderer, param);
}
/***********************************************************************//**
	$Id$
***************************************************************************/
}
}