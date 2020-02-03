/***********************************************************************//**
	@file
***************************************************************************/
#include "fk/render/Material.hpp"

namespace fk {
namespace render {
/***********************************************************************//**
	@brief デフォルトコンストラクタ
***************************************************************************/
Material::Material()
  : color_(1.0f), 
    blend_(Blend::Default), 
    face_(Face::Default)
{
}
/***********************************************************************//**
	@brief 
***************************************************************************/
void Material::merge(const Material& rhs) {
  if(rhs.getShader()) {
    setShader(rhs.getShader());
  }
  setColor(getColor() * rhs.getColor());
  if(rhs.getBlend() != Blend::Default) {
    setBlend(rhs.getBlend());
  }
  if(rhs.getFace() != Face::Default) {
    setFace(rhs.getFace());
  }
  if(rhs.getDepthTest() != DepthTest::Default) {
    setDepthTest(rhs.getDepthTest());
  }
}
/***********************************************************************//**
	@brief 
***************************************************************************/
void Material::apply(Renderer& renderer) const {
  SetBlend(getBlend());
  SetFace(getFace());
  SetDepthTest(getDepthTest());
}
/***********************************************************************//**
	@brief 
***************************************************************************/
void Material::SetBlend(Blend blend) {
  switch(blend) {
  case Blend::None:
    glDisable(GL_BLEND);
    break;
  case Blend::Add:
    glEnable(GL_BLEND);
    glBlendFunc(GL_ONE, GL_ONE);
    break;
  case Blend::AddAlpha:
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);
    break;
  case Blend::Alpha:
  case Blend::Default:
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    break;
  case Blend::Reverse:
    glEnable(GL_BLEND);
    glBlendFunc(GL_ONE_MINUS_DST_COLOR, GL_ZERO);
    break;
  }
}
/***********************************************************************//**
	@brief 
***************************************************************************/
void Material::SetFace(Face face) {
  switch(face) {
  case Face::Back:
    glEnable(GL_CULL_FACE);
    glCullFace(GL_FRONT);
    break;
  case Face::Both:
    glDisable(GL_CULL_FACE);
    break;
  case Face::Front:
  case Face::Default:
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
  }
}
/***********************************************************************//**
	@brief 
***************************************************************************/
void Material::SetDepthTest(DepthTest depthTest) {
  switch(depthTest) {
  case DepthTest::Always:
    glDepthFunc(GL_ALWAYS);
    break;
  case DepthTest::Equal:
    glDepthFunc(GL_EQUAL);
    break;
  case DepthTest::Greater:
    glDepthFunc(GL_GREATER);
    break;
  case DepthTest::GreaterEqual:
    glDepthFunc(GL_GEQUAL);
    break;
  case DepthTest::Less:
  case DepthTest::Default:
    glDepthFunc(GL_LESS);
    break;
  case DepthTest::LessEqual:
    glDepthFunc(GL_LEQUAL);
    break;
  case DepthTest::Never:
    glDepthFunc(GL_NEVER);
    break;
  case DepthTest::NotEqual:
    glDepthFunc(GL_NOTEQUAL);
    break;
  }
}
/***********************************************************************//**
	$Id$
***************************************************************************/
}
}
