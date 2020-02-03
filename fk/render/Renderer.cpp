/***********************************************************************//**
	@file
***************************************************************************/
#include "fk/camera/Camera.hpp"
#include "fk/render/Renderable.hpp"
#include "fk/render/Renderer.hpp"

namespace fk {
namespace render {
/***********************************************************************//**
	@brief コンストラクタ
***************************************************************************/
Renderer::Renderer(const ContextPtr& context)
  : ContextHolder<>(context), 
    defaultFrameBuffer_(0)
{
  glGetIntegerv(GL_FRAMEBUFFER_BINDING, &defaultFrameBuffer_);
}
/***********************************************************************//**
	@brief デストラクタ
***************************************************************************/
Renderer::~Renderer() {
}
/***********************************************************************//**
	@brief 
***************************************************************************/
void Renderer::beginRender(const IRect& viewport) {
  setViewport(viewport);
}
/***********************************************************************//**
	@brief 
***************************************************************************/
void Renderer::endRender() {
  checkError();
}
/***********************************************************************//**
	@brief 
***************************************************************************/
void Renderer::setViewport(const IRect& viewport) {
  viewport_ = viewport;
  glViewport(viewport.getPos().x, 
             viewport.getPos().y, 
             viewport.getSize().x, 
             viewport.getSize().y);
}
/***********************************************************************//**
	@brief 
***************************************************************************/
void Renderer::clear(ClearFlag flag, const glm::vec4& color) {
  glClearColor(color.r, color.g, color.b, color.a);
  glClear(((flag & CLEAR_COLOR) ? GL_COLOR_BUFFER_BIT : 0) | 
          ((flag & CLEAR_DEPTH) ? GL_DEPTH_BUFFER_BIT : 0) | 
          ((flag & CLEAR_STENCIL) ? GL_STENCIL_BUFFER_BIT : 0));
}
/***********************************************************************//**
	@brief 
***************************************************************************/
void Renderer::pushCamera(CameraPtr camera) {
  cameras_.push(camera);
  applyCamera(*camera);
}
/***********************************************************************//**
	@brief 
***************************************************************************/
void Renderer::popCamera() {
  cameras_.pop();
  applyCamera(*cameras_.top());
}
/***********************************************************************//**
	@brief 描画リクエスト
	@param[in] renderable 描画するもの
	@param[in] param 描画パラメーター
***************************************************************************/
void Renderer::render(RenderablePtr renderable, const RenderParam& param) {
  renderable->render(*this, param);
}
/***********************************************************************//**
	@brief 
***************************************************************************/
void Renderer::checkError() {
  for(auto error = glGetError();
      error != GL_NO_ERROR;
      error = glGetError()) {
    switch(error){
    case GL_INVALID_OPERATION:
      FK_WARNING("INVALID_OPERATOTION");
      break;
    case GL_INVALID_ENUM:
      FK_WARNING("INVALID_ENUM");
      break;
    case GL_INVALID_VALUE:
      FK_WARNING("INVALID_VALUE");
      break;
    case GL_OUT_OF_MEMORY:
      FK_WARNING("OUT_OF_MEMORY");
      break;
    case GL_INVALID_FRAMEBUFFER_OPERATION:
      FK_WARNING("INVALID_FRAMEBUFFER_OPERATION");
      break;
    default:
      FK_WARNING("ERROR");
      break;
    }
  }
}
/***********************************************************************//**
	@brief 
***************************************************************************/
void Renderer::applyCamera(const Camera& camera) {
  setViewport(camera.getViewport());
}
/***********************************************************************//**
	$Id$
***************************************************************************/
}
}
