/***********************************************************************//**
	@file
***************************************************************************/
#include "franken/outliner/Outliner.hpp"

namespace franken {
namespace outliner {
/***********************************************************************//**
	@brief コンストラクタ
        @param[in] parent 親ウィンドウ
        @param[in] context コンテキスト
***************************************************************************/
Outliner::Outliner(wxWindow* parent, const ContextPtr& context)
  : super(parent), 
    ContextHolder(context), 
    outliner_(new wxDataViewTreeCtrl(this, wxID_ANY))
{
  auto sizer = new wxBoxSizer(wxVERTICAL);
  sizer->Add(outliner_, wxSizerFlags().Expand().Proportion(1));
  SetSizerAndFit(sizer);
}
/***********************************************************************//**
	@brief デストラクタ
***************************************************************************/
Outliner::~Outliner() {
}
/***********************************************************************//**
	@brief 
***************************************************************************/
void Outliner::setRoot(const ObjectPtr& root) {
  root_ = root;
}
/***********************************************************************//**
	$Id$
***************************************************************************/
}
}
