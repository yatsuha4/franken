/***********************************************************************//**
	@file
***************************************************************************/
#include "fk/model/Vertex.hpp"

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
	$Id$
***************************************************************************/
}
}
