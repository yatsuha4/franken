/***********************************************************************//**
	@file
***************************************************************************/
#include "fk/framework/Context.hpp"
#include "fk/platform/wx/Canvas.hpp"
#include "fk/render/RenderParam.hpp"

namespace fk {
namespace platform {
namespace wx {
/***********************************************************************//**
	@brief コンストラクタ
	@param[in] parent 親ウィンドウ
	@param[in] attrs OpenGLアトリビュート
	@param[in] contextAttrs OpenGLコンテキストアトリビュート
	@param[in] context コンテキスト
***************************************************************************/
Canvas::Canvas(wxWindow* parent, 
               const wxGLAttributes& attrs, 
               const wxGLContextAttrs& contextAttrs, 
               const ContextPtr& context)
  : super(parent, attrs), 
    ContextHolder<>(context), 
    glContext_(this, nullptr, &contextAttrs), 
    timer_(this)
{
  Bind(wxEVT_PAINT, &Canvas::onPaint, this);
}
/***********************************************************************//**
	@brief デストラクタ
***************************************************************************/
Canvas::~Canvas() {
}
/***********************************************************************//**
	@brief 
***************************************************************************/
void Canvas::start(float fps) {
  stop();
  if(fps > 0.0f) {
    Bind(wxEVT_TIMER, &Canvas::onTimer, this);
    timer_.Start(int(1000.0f / fps));
  }
  else {
    Bind(wxEVT_IDLE, &Canvas::onIdle, this);
  }
  flag_.set(size_t(Flag::Start));
}
/***********************************************************************//**
	@brief 
***************************************************************************/
void Canvas::stop() {
  if(flag_.test(size_t(Flag::Start))) {
    if(timer_.IsRunning()) {
      timer_.Stop();
      Unbind(wxEVT_TIMER, &Canvas::onTimer, this);
    }
    else {
      Unbind(wxEVT_IDLE, &Canvas::onIdle, this);
    }
    flag_.reset(size_t(Flag::Start));
  }
}
/***********************************************************************//**
	@brief 
***************************************************************************/
void Canvas::update() {
  getContext()->update();
  Refresh();
}
/***********************************************************************//**
	@brief 
***************************************************************************/
void Canvas::render(const IRect& viewport) {
  getContext()->render(viewport, RenderParam());
}
/***********************************************************************//**
	@brief 
***************************************************************************/
void Canvas::onIdle(wxIdleEvent& event) {
  update();
  event.RequestMore();
}
/***********************************************************************//**
	@brief 
***************************************************************************/
void Canvas::onTimer(wxTimerEvent& event) {
  update();
}
/***********************************************************************//**
	@brief 
***************************************************************************/
void Canvas::onPaint(wxPaintEvent& event) {
  wxPaintDC dc(this);
  SetCurrent(glContext_);
  auto size = GetClientSize() * GetContentScaleFactor();
  render(IRect(glm::ivec2(0), glm::ivec2(size.x, size.y)));
  SwapBuffers();
}
/***********************************************************************//**
	$Id$
***************************************************************************/
}
}
}
