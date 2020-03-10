/***********************************************************************//**
	@file
***************************************************************************/
#pragma once

#include "fk/framework/Behaviour.hpp"
#include "fk/model/Mesh.hpp"

namespace fk::model {
/***********************************************************************//**
	@brief 
***************************************************************************/
class Model
  : public Behaviour
{
  using super = Behaviour;

 public:
  FK_DECLARE_CLASS(Object);

 private:
  std::vector<MeshPtr> meshes_;

 public:
  Model() = default;
  ~Model() = default;

  FK_REFER(Meshes, meshes_);
};
/***********************************************************************//**
	@brief 
***************************************************************************/
class Model::Object
  : public Behaviour
{
  using super = Behaviour;

 private:
  ModelPtr model_;
  std::vector<Mesh::ObjectPtr> meshes_;

 public:
  Object() = default;
  virtual ~Object() = default;

  void setModel(const ModelPtr& model);
};
/***********************************************************************//**
	$Id$
***************************************************************************/
}
