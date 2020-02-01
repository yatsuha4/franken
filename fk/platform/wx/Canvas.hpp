/***********************************************************************//**
	@file
***************************************************************************/
#pragma once

#include "fk/framework/ContextHolder.hpp"
#include "fk/math/Rect.hpp"

namespace fk {
namespace platform {
namespace wx {
/***********************************************************************//**
	@brief キャンバス
***************************************************************************/
class Canvas
  : public wxGLCanvas, 
    public ContextHolder<>
{
  using super = wxGLCanvas;

 private:
  enum class Flag {
    Start, 
    Max
  };

 private:
  wxGLContext glContext_;
  wxTimer timer_;
  std::bitset<static_cast<size_t>(Flag::Max)> flag_;

 public:
  Canvas(wxWindow* parent, 
         const wxGLAttributes& attrs, 
         const wxGLContextAttrs& contextAttrs, 
         const ContextPtr& context);
  ~Canvas() override;

  void start(float fps = 0.0f);
  void stop();

 protected:
  virtual void update();
  virtual void render(const IRect& viewport);

 private:
  void onIdle(wxIdleEvent& event);
  void onTimer(wxTimerEvent& event);
  void onPaint(wxPaintEvent& event);
};
/***********************************************************************//**
	$Id$
***************************************************************************/
}
}
}
