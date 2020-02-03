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
  std::bitset<size_t(Flag::Max)> flag_;
  std::array<ShaderPtr, size_t(Shader::Type::Max)> shaders_;
  std::array<GLint, size_t(Shader::Uniform::Max)> uniforms_;

 public:
  ShaderProgram();
  ~ShaderProgram();

  ShaderProgram& attach(const ShaderPtr& shader);
  ShaderProgram& link();

  ShaderProgram& use();
  ShaderProgram& unuse();

  template <class... Args>
  ShaderProgram& setUniform(Shader::Uniform uniform, const Args&... args) {
    return setUniform(uniforms_[size_t(uniform)], args...);
  }

  template <class... Args>
  ShaderProgram& setUniform(const char* name, const Args&... args) {
    return setUniform(getUniformLocation(name), args...);
  }

 private:
  FK_BIT_ACCESSOR(Link, flag_, Flag::Link);
  FK_BIT_ACCESSOR(Use, flag_, Flag::Use);

  void setupAttrib();
  void setupUniform();

  template <class... Args>
  ShaderProgram& setUniform(GLint location, const Args&... args) {
    FK_ASSERT(isUse());
    if(location >= 0) {
      setUniform(location, args...);
    }
    return *this;
  }

  GLint getUniformLocation(const char* name) const;

  void setUniform(GLint location, int value);
  void setUniform(GLint location, float value);
  void setUniform(GLint location, const glm::vec2& value);
  void setUniform(GLint location, const glm::vec3& value);
  void setUniform(GLint location, const glm::vec4& value);
  void setUniform(GLint location, const glm::mat3& value);
  void setUniform(GLint location, const glm::mat4& value);
};
/***********************************************************************//**
	$Id$
***************************************************************************/
}
}
