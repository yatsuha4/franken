/***********************************************************************//**
	@file
***************************************************************************/
#pragma once

#include "fk/render/Renderable.hpp"

namespace fk {
namespace model {
/***********************************************************************//**
	@brief ジオメトリ
***************************************************************************/
class Geometry
  : public Renderable
{
  using super = Geometry;

 public:
  static const size_t VERTEX_MAX = 0x10000;

  using index_t = uint16_t;

  enum class Mode {
    LineLoop, 
    LineStrip, 
    Lines, 
    Points, 
    TriangleFan, 
    TriangleStrip, 
    Triangles, 
    Null
  };

 private:
  enum class Buffer {
    Vertex, 
    Index, 
    Max
  };

 private:
  Mode mode_;
  std::array<GLuint, static_cast<size_t>(Buffer::Max)> buffers_;
  GLsizei indexNum_;
  MaterialPtr material_;

 public:
  Geometry();
  ~Geometry() override;

  void setup(Renderer& renderer, Mode mode, 
             size_t vertexNum, const Vertex* vertexes, 
             size_t indexNum, const index_t* indexes);

  FK_ACCESSOR(Material, material_);

 protected:
  void onRender(Renderer& renderer, const RenderParam& param) override;

 private:
  void clear();

  static GLenum GetMode(Mode mode);
};
/***********************************************************************//**
	$Id$
***************************************************************************/
}
}
