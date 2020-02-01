/***********************************************************************//**
	@file
***************************************************************************/
#pragma once

namespace franken {
namespace main {
/***********************************************************************//**
	@brief メインフレーム
***************************************************************************/
class MainFrame
  : public wxFrame, 
    public ContextHolder
{
  using super = wxFrame;

 private:
  wxAuiManager auiManager_;
  Outliner* outliner_;
  Inspector* inspector_;
  AssetBrowser* assetBrowser_;

 public:
  MainFrame(const ContextPtr& context);
  ~MainFrame() override;

 private:
  wxAuiNotebook* createNotebook();
};
/***********************************************************************//**
	$Id$
***************************************************************************/
}
}
