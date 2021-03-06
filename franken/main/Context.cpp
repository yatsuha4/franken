﻿/***********************************************************************//**
	@file
***************************************************************************/
#include "franken/main/Context.hpp"

namespace franken {
namespace main {
/***********************************************************************//**
	@brief コンストラクタ
        @param[in] application アプリケーション
***************************************************************************/
Context::Context(Application* application)
  : application_(application)
{
}
/***********************************************************************//**
	@brief デストラクタ
***************************************************************************/
Context::~Context() {
}
/***********************************************************************//**
	@brief 
***************************************************************************/
void Context::onRender(fk::Renderer& renderer, 
                       const fk::RenderParam& param) {
  renderer.clear(fk::Renderer::CLEAR_ALL, glm::vec4(0.5f, 0.5f, 0.5f, 0.0f));
  super::onRender(renderer, param);
}
/***********************************************************************//**
	$Id$
***************************************************************************/
}
}
