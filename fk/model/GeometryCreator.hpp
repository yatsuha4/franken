/***********************************************************************//**
	@file
***************************************************************************/
#pragma once

#include "fk/model/Geometry.hpp"
#include "fk/model/Vertex.hpp"

namespace fk {
namespace model {
/***********************************************************************//**
	@brief ジオメトリ生成クラス
***************************************************************************/
class GeometryCreator {
 private:
  std::vector<Vertex> vertexes_;
  std::vector<Geometry::index_t> indexes_;

 public:
  GeometryCreator() = default;
  ~GeometryCreator() = default;

  FK_ACCESSOR(Vertexes, vertexes_);
  FK_ACCESSOR(Indexes, indexes_);

  size_t appendVertex(const Vertex& vertex);
  void appendLine(const Vertex& p1, const Vertex& p2);

  GeometryPtr create(Renderer& renderer, Geometry::Mode mode);
  void setup(Geometry& geometry, Renderer& renderer, Geometry::Mode mode);
};
/***********************************************************************//**
	$Id$
***************************************************************************/
}
}
