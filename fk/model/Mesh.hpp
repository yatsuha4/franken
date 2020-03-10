/***********************************************************************//**
	@file
***************************************************************************/
#pragma once

#include "fk/framework/Behaviour.hpp"

namespace fk::model {
/***********************************************************************//**
	@brief 
***************************************************************************/
class Mesh
  : public Behaviour, 
    public std::enable_shared_from_this<Mesh>
{
  using super = Behaviour;

 public:
  FK_DECLARE_CLASS(Object);
  
 private:
  std::vector<ConstGeometryPtr> geometories_;

 public:
  Mesh() = default;
  virtual ~Mesh() = default;

  FK_REFER(Geometories, geometories_);

  virtual ObjectPtr createObject();
};
/***********************************************************************//**
	@brief 
***************************************************************************/
class Mesh::Object
  : public Behaviour
{
  using super = Behaviour;

 private:
  MeshPtr mesh_;

 public:
  Object(const MeshPtr& mesh);
  virtual ~Object() = default;

  FK_GETTER(Mesh, mesh_);
};
/***********************************************************************//**
	$Id$
***************************************************************************/
}
