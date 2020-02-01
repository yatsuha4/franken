﻿/***********************************************************************//**	@file***************************************************************************/#include "franken/main/Context.hpp"#include "franken/main/Object.hpp"namespace franken {namespace main {/***********************************************************************//**	@brief コンストラクタ        @param[in] context コンテキスト***************************************************************************/Object::Object(const ContextPtr& context)  : super(context){}/***********************************************************************//**	@brief デストラクタ***************************************************************************/Object::~Object() {}/***********************************************************************//**	@brief ***************************************************************************/ContextPtr Object::getContext() const {  return std::static_pointer_cast<Context>(super::getContext());}/***********************************************************************//**	$Id$***************************************************************************/}}