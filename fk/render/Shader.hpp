/***********************************************************************//**
	@file
***************************************************************************/
#pragma once

namespace fk {
namespace render {
/***********************************************************************//**
	@brief シェーダー
***************************************************************************/
class Shader {
 public:
  enum class Type {
    Vertex, 
    Fragment, 
    Geometry, 
    Max
  };

  enum class Attrib {
    Color, 
    MatrixIndexes, 
    MatrixWeights, 
    Normal, 
    Pos, 
    Uv, 
    Max
  };

  enum class Uniform {
    Color, 
    Matrixes, 
    ModelViewMatrix, 
    NormalMatrix, 
    ProjectionMatrix, 
    Textures, 
    UvMatrix, 
    Max
  };

 private:
  Type type_;
  GLuint id_;

 public:
  Shader(Type type, const char* source, size_t len = 0);
  ~Shader();

  FK_GETTER(Type, type_);
  FK_GETTER(Id, id_);

 private:
  static GLenum GetType(Type type);
};
/***********************************************************************//**
	$Id$
***************************************************************************/
}
}
