﻿/***********************************************************************//**	@file***************************************************************************/#include "franken/main/Property.hpp"namespace franken {namespace main {/***********************************************************************//**	@brief コンストラクタ        @param[in] name メンバー名        @param[in] label 表示名***************************************************************************/Property::Property(const wxString& name, const wxString& label)  : name_(name),     label_(label){}/***********************************************************************//**	@brief デストラクタ***************************************************************************/Property::~Property() {}/***********************************************************************//**	$Id$***************************************************************************/}}