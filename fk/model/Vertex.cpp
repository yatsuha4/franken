/***********************************************************************//**
	@file
***************************************************************************/
#include "fk/model/Vertex.hpp"
#include "fk/render/Shader.hpp"

namespace fk {
namespace model {
/***********************************************************************//**
	@brief デフォルトコンストラクタ
***************************************************************************/
Vertex::Vertex()
  : pos_(0.0f), 
    uv_(0.0f), 
    normal_(glm::packSnorm4x8(glm::vec4(0.0f, 1.0f, 0.0f, 0.0f))), 
    color_(glm::packUnorm4x8(glm::vec4(1.0f)))
{
  matrixIndexes_.fill(0);
  matrixWeights_.fill(0);
}
/***********************************************************************//**
	@brief 
***************************************************************************/
Vertex& Vertex::appendWeight(size_t index, float weight) {
  for(size_t i = 0;; i++) {
    FK_ASSERT(i < WEIGHT_MAX);
    if(matrixWeights_[i] == 0) {
      matrixIndexes_[i] = static_cast<uint8_t>(index);
      matrixWeights_[i] = static_cast<uint8_t>
        (weight * std::numeric_limits<uint8_t>::max() + 0.5f);
      break;
    }
  }
  return *this;
}
/***********************************************************************//**
	@brief 
***************************************************************************/
bool Vertex::operator==(const Vertex& rhs) const {
  return (pos_ == rhs.pos_ && 
          uv_ == rhs.uv_ && 
          normal_ == rhs.normal_ && 
          color_ == rhs.color_ && 
          matrixIndexes_ == rhs.matrixIndexes_ && 
          matrixWeights_ == rhs.matrixWeights_);
}
/***********************************************************************//**
	@brief 
***************************************************************************/
#define ENABLE_ATTRIB(attrib, member, size, type, normalized)   \
  glEnableVertexAttribArray(static_cast<GLuint>(attrib));       \
  glVertexAttribPointer(static_cast<GLuint>(attrib),            \
                        size, type, normalized, sizeof(Vertex), \
                        reinterpret_cast<const GLvoid*>         \
                        (offsetof(Vertex, member)))

void Vertex::EnableAttrib() {
  ENABLE_ATTRIB(Shader::Attrib::Pos, pos_, 3, GL_FLOAT, GL_FALSE);
  ENABLE_ATTRIB(Shader::Attrib::Uv, uv_, 2, GL_FLOAT, GL_FALSE);
  ENABLE_ATTRIB(Shader::Attrib::Normal, normal_, 4, GL_BYTE, GL_TRUE);
  ENABLE_ATTRIB(Shader::Attrib::Color, color_, 4, GL_UNSIGNED_BYTE, GL_TRUE);
  ENABLE_ATTRIB(Shader::Attrib::MatrixIndexes, matrixIndexes_, 4, 
                GL_UNSIGNED_BYTE, GL_FALSE);
  ENABLE_ATTRIB(Shader::Attrib::MatrixWeights, matrixWeights_, 4, 
                GL_UNSIGNED_BYTE, GL_TRUE);
}
/***********************************************************************//**
	$Id$
***************************************************************************/
}
}
