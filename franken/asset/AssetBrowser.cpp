﻿/***********************************************************************//**
	@file
***************************************************************************/
#include "franken/asset/AssetBrowser.hpp"
#include "franken/main/Config.hpp"
#include "franken/main/Context.hpp"

namespace franken {
namespace asset {
/***********************************************************************//**
	@brief コンストラクタ
***************************************************************************/
AssetBrowser::AssetBrowser(wxWindow* parent, const ContextPtr& context)
  : super(parent), 
    ContextHolder(context), 
    dirView_(new wxDataViewTreeCtrl(this, wxID_ANY))
{
  auto projectDir = getContext()->getConfig()->getProjectDir();
  if(!projectDir.IsEmpty()) {
    wxDir dir(projectDir);
    updateDir(dir, wxDataViewItem());
  }
  auto sizer = new wxBoxSizer(wxHORIZONTAL);
  sizer->Add(dirView_, wxSizerFlags().Expand().Proportion(1));
  SetSizerAndFit(sizer);
}
/***********************************************************************//**
	@brief デストラクタ
***************************************************************************/
AssetBrowser::~AssetBrowser() {
}
/***********************************************************************//**
	@brief 
***************************************************************************/
void AssetBrowser::updateDir(wxDir& dir, const wxDataViewItem& parent) {
  if(dir.IsOpened()) {
    wxLogDebug("dir %s", dir.GetName());
    wxString iter;
    if(dir.GetFirst(&iter, wxEmptyString, wxDIR_DIRS)) {
      do {
        wxDir subDir(wxFileName(dir.GetName(), iter).GetFullPath());
        if(subDir.IsOpened()) {
          if(subDir.HasSubDirs()) {
            auto item = dirView_->AppendContainer(parent, iter);
            dirView_->SetItemIcon(item, wxArtProvider::GetIcon(wxART_FOLDER));
            updateDir(subDir, item);
          }
          else {
            auto item = dirView_->AppendItem(parent, iter);
            dirView_->SetItemIcon(item, wxArtProvider::GetIcon(wxART_FOLDER));
          }
        }
      } while(dir.GetNext(&iter));
    }
  }
}
/***********************************************************************//**
	$Id$
***************************************************************************/
}
}
