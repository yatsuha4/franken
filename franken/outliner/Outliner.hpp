﻿/***********************************************************************//**
	@file
***************************************************************************/
#pragma once

namespace franken {
namespace outliner {
/***********************************************************************//**
	@brief アウトライナ
***************************************************************************/
class Outliner
  : public wxPanel, 
    public ContextHolder
{
  using super = wxPanel;

 private:
  ObjectPtr root_;
  wxDataViewTreeCtrl* outliner_;

 public:
  Outliner(wxWindow* parent, const ContextPtr& context);
  ~Outliner() override;

  void setRoot(const ObjectPtr& root);
  FK_GETTER(Root, root_);
};
/***********************************************************************//**
	$Id$
***************************************************************************/
}
}
