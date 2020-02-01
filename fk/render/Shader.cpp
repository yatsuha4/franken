/***********************************************************************//**
	@file
***************************************************************************/
#include "fk/render/Shader.hpp"

namespace fk {
namespace render {
/***********************************************************************//**
	@brief コンストラクタ
***************************************************************************/
Shader::Shader(Type type, const char* source, size_t len)
  : type_(type), 
    id_(glCreateShader(GetType(type)))
{
  auto pt = static_cast<const GLchar*>(source);
  auto size = GLint((len == 0) ? strlen(source) : len);
  glShaderSource(id_, 1, &pt, &size);
  glCompileShader(id_);
#if !defined(FK_MASTER)
  {
    GLint length;
    glGetShaderiv(id_, GL_INFO_LOG_LENGTH, &length);
    if(length > 1) {
      std::vector<GLchar> buffer(length);
      glGetShaderInfoLog(id_, length, 0, buffer.data());
      FK_WARNING("Shader compile error: %s", buffer.data());
    }
  }
#endif
}
/***********************************************************************//**
	@brief デストラクタ
***************************************************************************/
Shader::~Shader() {
  glDeleteShader(id_);
}
/***********************************************************************//**
	@brief 
***************************************************************************/
GLenum Shader::GetType(Type type) {
  switch(type) {
  case Type::Vertex:
    return GL_VERTEX_SHADER;
  case Type::Fragment:
    return GL_FRAGMENT_SHADER;
  case Type::Geometry:
  default:
    return GL_GEOMETRY_SHADER;
  }
}
/***********************************************************************//**
	$Id$
***************************************************************************/
}
}
