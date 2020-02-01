﻿/***********************************************************************//**
	@file
***************************************************************************/
#include "franken/gui/Canvas.hpp"
#include "franken/main/Context.hpp"

namespace franken {
namespace gui {
/***********************************************************************//**
	@brief コンストラクタ
***************************************************************************/
Canvas::Canvas(wxWindow* parent, const ContextPtr& context)
  : super(parent, GetAttrs(), GetContextAttrs(), context)
{
}
/***********************************************************************//**
	@brief デストラクタ
***************************************************************************/
Canvas::~Canvas() {
}
/***********************************************************************//**
	@brief 
***************************************************************************/
wxGLAttributes Canvas::GetAttrs() {
  wxGLAttributes attrs;
  attrs.Defaults().EndList();
  return attrs;
}
/***********************************************************************//**
	@brief 
***************************************************************************/
wxGLContextAttrs Canvas::GetContextAttrs() {
  wxGLContextAttrs attrs;
  attrs.CompatibilityProfile().EndList();
  return attrs;
}
/***********************************************************************//**
	$Id$
***************************************************************************/
}
}