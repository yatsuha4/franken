﻿/***********************************************************************//**
	@file
***************************************************************************/
#include "franken/main/Application.hpp"
#include "franken/main/Config.hpp"
#include "franken/main/Context.hpp"
#include "franken/main/MainFrame.hpp"

namespace franken {
namespace main {
/***********************************************************************//**
	@brief コンストラクタ
***************************************************************************/
Application::Application()
  : mainFrame_(nullptr)
{
}
/***********************************************************************//**
	@brief デストラクタ
***************************************************************************/
Application::~Application() {
}
/***********************************************************************//**
	@brief 
***************************************************************************/
bool Application::OnCmdLineParsed(wxCmdLineParser& parser) {
  if(!super::OnCmdLineParsed(parser)) {
    return false;
  }
  auto context = getContext();
  context->setConfig(std::make_shared<Config>());
  mainFrame_ = new MainFrame(context);
  mainFrame_->Show();
  SetTopWindow(mainFrame_);
  return true;
}
/***********************************************************************//**
	@brief 
***************************************************************************/
fk::ContextPtr Application::createContext() {
  return std::make_shared<Context>(this);
}
/***********************************************************************//**
	@brief 
***************************************************************************/
ContextPtr Application::getContext() const {
  return std::static_pointer_cast<Context>(super::getContext());
}
/***********************************************************************//**
	$Id$
***************************************************************************/
}
}
