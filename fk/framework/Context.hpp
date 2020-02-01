﻿/***********************************************************************//**
	@file
***************************************************************************/
#pragma once

#include "fk/framework/Object.hpp"

namespace fk {
namespace framework {
/***********************************************************************//**
	@brief コンテキスト
***************************************************************************/
class Context
  : public Object
{
  using super = Object;

 private:
  RendererPtr renderer_;

 public:
  Context();
  ~Context() override;

  void render(const RenderParam& param);

 protected:
  virtual RendererPtr createRenderer();
};
/***********************************************************************//**
	$Id$
***************************************************************************/
}
}
