﻿/***********************************************************************//**
	@file
***************************************************************************/
#pragma once

namespace franken {
namespace asset {
/***********************************************************************//**
	@brief アセットブラウザ
***************************************************************************/
class AssetBrowser
  : public wxPanel, 
    public ContextHolder
{
  using super = wxPanel;

 private:
  wxDataViewTreeCtrl* dirView_;

 public:
  AssetBrowser(wxWindow* parent, const ContextPtr& context);
  ~AssetBrowser() override;

 private:
  void updateDir(wxDir& dir, const wxDataViewItem& parent);
};
/***********************************************************************//**
	$Id$
***************************************************************************/
}
}
