/***********************************************************************//**
	@file
***************************************************************************/
#pragma once

namespace franken {
namespace main {
/***********************************************************************//**
	@brief コンテキスト
***************************************************************************/
class Context
  : public fk::Context
{
  using super = fk::Context;

 private:
  Application* application_;
  ConfigPtr config_;

 public:
  Context(Application* application);
  ~Context() override;

  FK_GETTER(Application, application_);
  FK_ACCESSOR(Config, config_);
};
/***********************************************************************//**
	$Id$
***************************************************************************/
}
}
