﻿/***********************************************************************//**	@file***************************************************************************/#pragma oncenamespace franken {namespace framework {/***********************************************************************//**	@brief ***************************************************************************/class Application  : public fk::platform::wx::Application{  using super = fk::platform::wx::Application; private:  MainFrame* mainFrame_; public:  Application();  ~Application() override; protected:  bool OnCmdLineParsed(wxCmdLineParser& parser) override;};/***********************************************************************//**	$Id$***************************************************************************/}}