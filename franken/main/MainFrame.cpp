/***********************************************************************//**
	@file
***************************************************************************/
#include "franken/asset/AssetBrowser.hpp"
#include "franken/gui/Canvas.hpp"
#include "franken/inspector/Inspector.hpp"
#include "franken/main/MainFrame.hpp"
#include "franken/outliner/Outliner.hpp"

namespace franken {
namespace main {
static const wxSize OUTLINER_SIZE(300, 600);
static const wxSize INSPECTOR_SIZE(300, 600);
static const wxSize ASSET_BROWSER_SIZE(1200, 300);
/***********************************************************************//**
	@brief コンストラクタ
        @param[in] context コンテキスト
***************************************************************************/
MainFrame::MainFrame(const ContextPtr& context)
  : super(nullptr, wxID_ANY, "Franken", wxDefaultPosition, wxSize(1200, 900)), 
    ContextHolder(context), 
    auiManager_(this)
{
  {
    auto notebook = createNotebook();
    canvas_ = new Canvas(notebook, context);
    notebook->AddPage(canvas_, "Canvas");
    auiManager_.AddPane(notebook, 
                        wxAuiPaneInfo().
                        CaptionVisible(false).
                        Center());
  }
  {
    auto notebook = createNotebook();
    outliner_ = new Outliner(notebook, context);
    notebook->AddPage(outliner_, "Outliner");
    auiManager_.AddPane(notebook, 
                        wxAuiPaneInfo().
                        CaptionVisible(false).
                        Left().
                        BestSize(OUTLINER_SIZE));
  }
  {
    auto notebook = createNotebook();
    inspector_ = new Inspector(notebook, context);
    notebook->AddPage(inspector_, "Inspector");
    auiManager_.AddPane(notebook, 
                        wxAuiPaneInfo().
                        CaptionVisible(false).
                        Layer(1).
                        Right().
                        BestSize(INSPECTOR_SIZE));
  }
  {
    auto notebook = createNotebook();
    assetBrowser_ = new AssetBrowser(notebook, context);
    notebook->AddPage(assetBrowser_, "AssetBrowser");
    auiManager_.AddPane(notebook, 
                        wxAuiPaneInfo().
                        CaptionVisible(false).
                        Bottom().
                        BestSize(ASSET_BROWSER_SIZE));
  }
  auiManager_.Update();
}
/***********************************************************************//**
	@brief デストラクタ
***************************************************************************/
MainFrame::~MainFrame() {
  auiManager_.UnInit();
}
/***********************************************************************//**
	@brief 
***************************************************************************/
wxAuiNotebook* MainFrame::createNotebook() {
  auto notebook = 
    new wxAuiNotebook(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 
                      wxAUI_NB_DEFAULT_STYLE & 
                      ~wxAUI_NB_CLOSE_ON_ACTIVE_TAB & 
                      ~wxAUI_NB_MIDDLE_CLICK_CLOSE);
  return notebook;
}
/***********************************************************************//**
	$Id$
***************************************************************************/
}
}
