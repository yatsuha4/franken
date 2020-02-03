/***********************************************************************//**
	@file
***************************************************************************/
#include "fk/camera/Camera.hpp"

namespace fk {
namespace camera {
/***********************************************************************//**
	@brief デフォルトコンストラクタ
***************************************************************************/
Camera::Camera()
  : viewport_(glm::vec2(0), glm::vec2(0)), 
    near_(0.0f), 
    far_(0.0f)
{
}
/***********************************************************************//**
	@brief ワールド座標をスクリーン座標に変換する
	@param[in] pos ワールド座標
	@return スクリーン座標
***************************************************************************/
glm::vec3 Camera::worldToScreen(const glm::vec3& pos) const {
  auto& viewport = getViewport();
  return glm::project(pos, getModelViewMatrix(), getProjectionMatrix(), 
                      glm::vec4(viewport.getLeft(), 
                                -viewport.getBottom(), 
                                viewport.getWidth(), 
                                viewport.getHeight()));
}
/***********************************************************************//**
	@brief スクリーン座標をワールド座標に変換する
	@param[in] pos スクリーン座標
	@return ワールド座標
***************************************************************************/
glm::vec3 Camera::screenToWorld(const glm::vec3& pos) const {
  const auto& viewport = getViewport();
  return glm::unProject(pos, 
                        getModelViewMatrix(), 
                        getProjectionMatrix(), 
                        glm::vec4(viewport.getLeft(), 
                                  -viewport.getBottom(), 
                                  viewport.getWidth(), 
                                  viewport.getHeight()));
}
/***********************************************************************//**
	$Id$
***************************************************************************/
}
}
