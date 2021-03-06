﻿/***********************************************************************//**
	@file
***************************************************************************/
#pragma once

namespace franken {
namespace main {
/***********************************************************************//**
	@brief コンポーネント
***************************************************************************/
class Component
  : public fk::Component
{
  using super = fk::Component;

 private:
  std::vector<PropertyPtr> properties_;

 public:
  Component(const ObjectPtr& object);
  ~Component();

 protected:
  PropertyPtr appendProperty(const wxString& name, const wxString& label);
};
/***********************************************************************//**
	$Id$
***************************************************************************/
}
}
