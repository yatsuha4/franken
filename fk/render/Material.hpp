/***********************************************************************//**
	@file
***************************************************************************/
#pragma once

namespace fk {
namespace render {
/***********************************************************************//**
	@brief マテリアル
***************************************************************************/
class Material {
 public:
  enum class Blend {
    Default, 
    None, 
    Add, 
    AddAlpha, 
    Alpha, 
    Reverse
  };

  enum class Face {
    Default, 
    Back, 
    Both, 
    Front, 
  };

  enum class DepthTest {
    Default, 
    Always, 
    Equal, 
    Greater, 
    GreaterEqual, 
    Less, 
    LessEqual, 
    Never, 
    NotEqual
  };

 private:
  ShaderProgramPtr shader_;
  glm::vec4 color_;
  Blend blend_;
  Face face_;
  DepthTest depthTest_;

 public:
  Material();
  Material(const Material& src) = default;
  ~Material() = default;

  FK_ACCESSOR(Shader, shader_);
  FK_ACCESSOR(Color, color_);
  FK_ACCESSOR(Blend, blend_);
  FK_ACCESSOR(Face, face_);
  FK_ACCESSOR(DepthTest, depthTest_);

  void merge(const Material& rhs);
  void apply(Renderer& renderer) const;

 private:
  static void SetBlend(Blend blend);
  static void SetFace(Face face);
  static void SetDepthTest(DepthTest depthTest);
};
/***********************************************************************//**
	$Id$
***************************************************************************/
}
}
