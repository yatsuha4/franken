/***********************************************************************//**
	@file
***************************************************************************/
#include "fk/render/ShaderProgram.hpp"

namespace fk {
namespace render {
/***********************************************************************//**
	@brief コンストラクタ
***************************************************************************/
ShaderProgram::ShaderProgram()
  : id_(glCreateProgram())
{
}
/***********************************************************************//**
	@brief デストラクタ
***************************************************************************/
ShaderProgram::~ShaderProgram() {
  glDeleteProgram(id_);
}
/***********************************************************************//**
	@brief 
***************************************************************************/
ShaderProgram& ShaderProgram::attach(const ShaderPtr& shader) {
  FK_ASSERT(!isLink());
  shaders_[size_t(shader->getType())] = shader;
  glAttachShader(id_, shader->getId());
  return *this;
}
/***********************************************************************//**
	@brief 
***************************************************************************/
ShaderProgram& ShaderProgram::link() {
  FK_ASSERT(!isLink());
  setLink(true);
  setupAttrib();
  glLinkProgram(id_);
  setupUniform();
  return *this;
}
/***********************************************************************//**
	@brief 
***************************************************************************/
ShaderProgram& ShaderProgram::use() {
  FK_ASSERT(isLink());
  FK_ASSERT(!isUse());
  setUse(true);
  glUseProgram(id_);
  return *this;
}
/***********************************************************************//**
	@brief 
***************************************************************************/
ShaderProgram& ShaderProgram::unuse() {
  FK_ASSERT(isUse());
  setUse(false);
  glUseProgram(0);
  return *this;
}
/***********************************************************************//**
	@brief 
***************************************************************************/
void ShaderProgram::setupAttrib() {
  static const char* ATTRIBS[size_t(Shader::Attrib::Max)] = {
    "Color", 
    "MatrixIndexes", 
    "MatrixWeights"
    "Normal", 
    "Pos", 
    "Uv", 
  };
  for(GLuint i = 0; i < GLuint(Shader::Attrib::Max); i++) {
    glBindAttribLocation(id_, i, ATTRIBS[i]);
  }
}
/***********************************************************************//**
	@brief 
***************************************************************************/
void ShaderProgram::setupUniform() {
  static const char* UNIFORMS[size_t(Shader::Uniform::Max)] = {
    "Color", 
    "Matrixes", 
    "ModelViewMatrix", 
    "NormalMatrix", 
    "ProjectionMatrix", 
    "Textures", 
    "UvMatrix"
  };
  for(size_t i = 0; i < size_t(Shader::Uniform::Max); i++) {
    uniforms_[i] = getUniformLocation(UNIFORMS[i]);
  }
}
/***********************************************************************//**
	@brief 
***************************************************************************/
GLint ShaderProgram::getUniformLocation(const char* name) const {
  return glGetUniformLocation(id_, name);
}
/***********************************************************************//**
	@brief 
***************************************************************************/
void ShaderProgram::setUniform(GLint location, int value) {
  glUniform1i(location, value);
}
/***********************************************************************//**
	@brief 
***************************************************************************/
void ShaderProgram::setUniform(GLint location, float value) {
  glUniform1f(location, value);
}
/***********************************************************************//**
	@brief 
***************************************************************************/
void ShaderProgram::setUniform(GLint location, const glm::vec2& value) {
  glUniform2fv(location, 1, glm::value_ptr(value));
}
/***********************************************************************//**
	@brief 
***************************************************************************/
void ShaderProgram::setUniform(GLint location, const glm::vec3& value) {
  glUniform3fv(location, 1, glm::value_ptr(value));
}
/***********************************************************************//**
	@brief 
***************************************************************************/
void ShaderProgram::setUniform(GLint location, const glm::vec4& value) {
  glUniform4fv(location, 1, glm::value_ptr(value));
}
/***********************************************************************//**
	@brief 
***************************************************************************/
void ShaderProgram::setUniform(GLint location, const glm::mat3& value) {
  glUniformMatrix3fv(location, 1, GL_FALSE, glm::value_ptr(value));
}
/***********************************************************************//**
	@brief 
***************************************************************************/
void ShaderProgram::setUniform(GLint location, const glm::mat4& value) {
  glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(value));
}
/***********************************************************************//**
	$Id$
***************************************************************************/
}
}
