/***********************************************************************//**
	@file
***************************************************************************/
#pragma once

namespace fk {
namespace model {
/***********************************************************************//**
	@brief 頂点
***************************************************************************/
class Vertex {
 public:
  static const size_t WEIGHT_MAX = 4;

 private:
  glm::vec3 pos_;
  glm::vec2 uv_;
  glm::uint normal_;
  glm::uint color_;
  std::array<uint8_t, WEIGHT_MAX> matrixIndexes_;
  std::array<uint8_t, WEIGHT_MAX> matrixWeights_;

 public:
  Vertex();
  ~Vertex() = default;

  FK_ACCESSOR(Pos, pos_);
  FK_ACCESSOR(Uv, uv_);

  Vertex& setNormal(const glm::vec3& normal) {
    normal_ = glm::packSnorm4x8(glm::vec4(glm::normalize(normal), 0.0f));
    return *this;
  }

  glm::vec3 getNormal() const {
    return glm::vec3(glm::unpackSnorm4x8(normal_));
  }

  Vertex& setColor(const glm::vec4& color) {
    color_ = glm::packUnorm4x8(color);
    return *this;
  }

  glm::vec4 getColor() const {
    return glm::unpackUnorm4x8(color_);
  }

  Vertex& appendWeight(size_t index, float weight);

  bool operator==(const Vertex& rhs) const;
};
/***********************************************************************//**
	$Id$
***************************************************************************/
}
}
