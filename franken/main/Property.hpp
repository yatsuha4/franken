﻿/***********************************************************************//**
	@file
***************************************************************************/
#pragma once

namespace franken {
namespace main {
/***********************************************************************//**
	@brief プロパティ
***************************************************************************/
class Property {
 private:
  wxString name_;
  wxString label_;
  wxAny value_;

 public:
  Property(const wxString& name, const wxString& label);
  ~Property();

  FK_GETTER(Name, name_);
  FK_GETTER(Label, label_);
  FK_ACCESSOR(Value, value_);
};
/***********************************************************************//**
	$Id$
***************************************************************************/
}
}
