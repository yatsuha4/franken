/***********************************************************************//**
	@file
***************************************************************************/
#pragma once

#include "fk/render/Shader.hpp"

namespace fk {
namespace render {
/***********************************************************************//**
	@brief 
***************************************************************************/
class ShaderProgram {
 private:
  enum class Flag {
    Link, 
    Use, 
    Max
  };

 private:
  GLuint id_;
  std::array<ShaderPtr, size_t(Shader::Type::Max)> shaders_;
  std::bitset<size_t(Flag::Max)> flag_;

 public:
  ShaderProgram();
  ~ShaderProgram();

  ShaderProgram& attach(const ShaderPtr& shader);
  ShaderProgram& link();

  ShaderProgram& use();
  ShaderProgram& unuse();

 private:
  FK_BIT_ACCESSOR(Link, flag_, Flag::Link);
  FK_BIT_ACCESSOR(Use, flag_, Flag::Use);
};
/***********************************************************************//**
	$Id$
***************************************************************************/
}
}
