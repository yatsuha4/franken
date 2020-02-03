/***********************************************************************//**
	@file
***************************************************************************/
#include "fk/model/GeometryCreator.hpp"

namespace fk {
namespace model {
/***********************************************************************//**
	@brief 
***************************************************************************/
size_t GeometryCreator::appendVertex(const Vertex& vertex) {
  auto index = vertexes_.size();
  vertexes_.emplace_back(vertex);
  return index;
}
/***********************************************************************//**
	@brief 
***************************************************************************/
void GeometryCreator::appendLine(const Vertex& p1, const Vertex& p2) {
  indexes_.push_back(appendVertex(p1));
  indexes_.push_back(appendVertex(p2));
}
/***********************************************************************//**
	@brief 
***************************************************************************/
GeometryPtr GeometryCreator::create(Renderer& renderer, 
                                    Geometry::Mode mode) {
  auto geometry = std::make_shared<Geometry>();
  setup(*geometry, renderer, mode);
  return geometry;
}
/***********************************************************************//**
	@brief 
***************************************************************************/
void GeometryCreator::setup(Geometry& geometry, Renderer& renderer, 
                            Geometry::Mode mode) {
  geometry.setup(renderer, mode, vertexes_.size(), vertexes_.data(), 
                 indexes_.size(), indexes_.data());
  vertexes_.clear();
  indexes_.clear();
}
/***********************************************************************//**
	$Id$
***************************************************************************/
}
}
