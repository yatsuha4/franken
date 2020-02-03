/***********************************************************************//**
	@file
***************************************************************************/
#pragma once

#include "fk/render/Material.hpp"

namespace fk {
namespace render {
/***********************************************************************//**
	@brief 描画パラメーター
***************************************************************************/
class RenderParam
  : public Material
{
  using super = Material;

 private:
  glm::mat4 matrix_;

 public:
  RenderParam();
  RenderParam(const Material& src);
  RenderParam(const RenderParam& src) = default;
  ~RenderParam() = default;

  FK_ACCESSOR(Matrix, matrix_);

  void merge(const RenderParam& rhs);
};
/***********************************************************************//**
	$Id$
***************************************************************************/
}
}
