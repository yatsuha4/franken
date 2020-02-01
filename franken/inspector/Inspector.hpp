/***********************************************************************//**
	@file
***************************************************************************/
#pragma once

namespace franken {
namespace inspector {
/***********************************************************************//**
	@brief インスペクタ
***************************************************************************/
class Inspector
  : public wxPanel, 
    public ContextHolder
{
  using super = wxPanel;

 private:
  wxPropertyGrid* grid_;
  ObjectPtr object_;

 public:
  Inspector(wxWindow* parent, const ContextPtr& context);
  ~Inspector() override;

  void show(const ObjectPtr& object);
};
/***********************************************************************//**
	$Id$
***************************************************************************/
}
}
