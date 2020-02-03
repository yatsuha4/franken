/***********************************************************************//**
	@file
***************************************************************************/
#include "fk/model/Geometry.hpp"
#include "fk/model/Vertex.hpp"

namespace fk {
namespace model {
/***********************************************************************//**
	@brief コンストラクタ
***************************************************************************/
Geometry::Geometry()
  : mode_(Mode::Null), 
    indexNum_(0)
{
  buffers_.fill(0);
}
/***********************************************************************//**
	@brief デストラクタ
***************************************************************************/
Geometry::~Geometry() {
  clear();
}
/***********************************************************************//**
	@brief 
***************************************************************************/
void Geometry::setup(Renderer& renderer, Mode mode, 
                     size_t vertexNum, const Vertex* vertexes, 
                     size_t indexNum, const index_t* indexes) {
  FK_ASSERT(mode != Mode::Null && vertexNum < VERTEX_MAX);
  clear();
  mode_ = mode;
  indexNum_ = static_cast<GLsizei>(indexNum);
  glGenBuffers(static_cast<size_t>(Buffer::Max), buffers_.data());
  glBindBuffer(GL_ARRAY_BUFFER, 
               buffers_[static_cast<size_t>(Buffer::Vertex)]);
  glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * vertexNum, vertexes, 
               GL_STATIC_DRAW);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 
               buffers_[static_cast<size_t>(Buffer::Index)]);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(index_t) * indexNum, indexes, 
               GL_STATIC_DRAW);
}
/***********************************************************************//**
	@copydoc Renderable::onRender
***************************************************************************/
void Geometry::onRender(Renderer& renderer, const RenderParam& param) {
  if(mode_ != Mode::Null) {
    glBindBuffer(GL_ARRAY_BUFFER, 
                 buffers_[static_cast<size_t>(Buffer::Vertex)]);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 
                 buffers_[static_cast<size_t>(Buffer::Index)]);
    Vertex::EnableAttrib();
    glDrawElements(GetMode(mode_), indexNum_, GL_UNSIGNED_SHORT, 0);
  }
}
/***********************************************************************//**
	@brief 
***************************************************************************/
void Geometry::clear() {
  if(mode_ != Mode::Null) {
    glDeleteBuffers(static_cast<size_t>(Buffer::Max), buffers_.data());
    mode_ = Mode::Null;
  }
}
/***********************************************************************//**
	@brief 
***************************************************************************/
GLenum Geometry::GetMode(Mode mode) {
  static const GLenum MODES[] = {
    GL_LINE_LOOP, 
    GL_LINE_STRIP, 
    GL_LINES, 
    GL_POINTS, 
    GL_TRIANGLE_FAN, 
    GL_TRIANGLE_STRIP, 
    GL_TRIANGLES
  };
  return MODES[static_cast<size_t>(mode)];
}
/***********************************************************************//**
	$Id$
***************************************************************************/
}
}
