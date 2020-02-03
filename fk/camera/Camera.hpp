/***********************************************************************//**
	@file
***************************************************************************/
#pragma once

#include "fk/math/Rect.hpp"

namespace fk {
namespace camera {
/***********************************************************************//**
	@brief カメラ基底クラス
***************************************************************************/
class Camera {
 private:
  IRect viewport_;
  float near_;
  float far_;
  glm::mat4 projectionMatrix_;
  glm::mat4 modelViewMatrix_;

 public:
  Camera();
  Camera(const Camera& src) = default;
  ~Camera() = default;

  FK_ACCESSOR(Viewport, viewport_);
  FK_ACCESSOR(Near, near_);
  FK_ACCESSOR(Far, far_);
  FK_ACCESSOR(ProjectionMatrix, projectionMatrix_);
  FK_ACCESSOR(ModelViewMatrix, modelViewMatrix_);

  glm::vec3 worldToScreen(const glm::vec3& pos) const;
  glm::vec3 screenToWorld(const glm::vec3& pos) const;
};
/***********************************************************************//**
	$Id$
***************************************************************************/
}
}
