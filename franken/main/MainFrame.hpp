﻿/***********************************************************************//**	@file***************************************************************************/#pragma oncenamespace franken {namespace main {/***********************************************************************//**	@brief メインフレーム***************************************************************************/class MainFrame  : public wxFrame{  using super = wxFrame; private:  Application* application_;  wxAuiManager auiManager_;  AssetBrowser* assetBrowser_; public:  MainFrame(Application* application);  ~MainFrame() override;};/***********************************************************************//**	$Id$***************************************************************************/}}