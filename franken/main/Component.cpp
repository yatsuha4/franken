﻿/***********************************************************************//**
	@file
***************************************************************************/
#include "franken/main/Component.hpp"
#include "franken/main/Object.hpp"
#include "franken/main/Property.hpp"

namespace franken {
namespace main {
/***********************************************************************//**
	@brief コンストラクタ
***************************************************************************/
Component::Component(const ObjectPtr& object)
  : super(object)
{
}
/***********************************************************************//**
	@brief デストラクタ
***************************************************************************/
Component::~Component() {
}
/***********************************************************************//**
	@brief プロパティを追加する
        @param[in] name プロパティ名
        @param[in] label 表示名
        @return 追加したプロパティ
***************************************************************************/
PropertyPtr Component::appendProperty(const wxString& name, 
                                      const wxString& label) {
  auto property = std::make_shared<Property>(name, label);
  properties_.push_back(property);
  return property;
}
/***********************************************************************//**
	$Id$
***************************************************************************/
}
}
