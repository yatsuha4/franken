/***********************************************************************//**
	@file
***************************************************************************/
#pragma once

namespace fk {
namespace platform {
namespace wx {
/***********************************************************************//**
	@brief wxWidgetsを使ったアプリケーション
***************************************************************************/
class Application
  : public wxApp
{
  using super = wxApp;

 private:
  ContextPtr context_;

 public:
  Application();
  ~Application() override;

 protected:
  FK_GETTER(Context, context_);

  virtual ContextPtr createContext();

  void OnInitCmdLine(wxCmdLineParser& parser) override;
};
/***********************************************************************//**
	$Id$
***************************************************************************/
}
}
}
