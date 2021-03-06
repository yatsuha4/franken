﻿/***********************************************************************//**
	@file
***************************************************************************/
#include "franken/inspector/Inspector.hpp"
#include "franken/main/Object.hpp"

namespace franken {
namespace inspector {
/***********************************************************************//**
	@brief コンストラクタ
***************************************************************************/
Inspector::Inspector(wxWindow* parent, const ContextPtr& context)
  : super(parent), 
    ContextHolder(context), 
    grid_(new wxPropertyGrid(this))
{
  auto sizer = new wxBoxSizer(wxVERTICAL);
  sizer->Add(grid_, wxSizerFlags().Expand().Proportion(1));
  SetSizerAndFit(sizer);
}
/***********************************************************************//**
	@brief デストラクタ
***************************************************************************/
Inspector::~Inspector() {
}
/***********************************************************************//**
	@brief 
***************************************************************************/
void Inspector::show(const ObjectPtr& object) {
  object_ = object;
}
/***********************************************************************//**
	$Id$
***************************************************************************/
}
}
