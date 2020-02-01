/***********************************************************************//**
	@file
***************************************************************************/
#pragma once

namespace franken {
namespace gui {
/***********************************************************************//**
	@brief 
***************************************************************************/
class Canvas
  : public fk::wx::Canvas
{
  using super = fk::wx::Canvas;

 public:
  Canvas(wxWindow* parent, const ContextPtr& context);
  ~Canvas() override;

 private:
  static wxGLAttributes GetAttrs();
  static wxGLContextAttrs GetContextAttrs();
};
/***********************************************************************//**
	$Id$
***************************************************************************/
}
}
