/***********************************************************************//**
	@file
***************************************************************************/
#include "franken/main/ColumnBrowser.hpp"

namespace franken {
namespace main {
/***********************************************************************//**
	@brief コンストラクタ
        @param[in] parent 親ウィンドウ
***************************************************************************/
ColumnBrowser::ColumnBrowser(wxWindow* parent)
  : super(parent)
{
  auto sizer = new wxBoxSizer(wxHORIZONTAL);
  SetSizer(sizer);
  {
    static const char* ITEMS[] = {
      "APPLE", 
      "BANANA", 
      "CHERRY"
    };
    auto list = std::make_shared<ItemList>();
    for(auto item : ITEMS) {
      list->push_back(std::make_shared<Item>(item));
    }
    open(list);
  }
}
/***********************************************************************//**
	@brief 
***************************************************************************/
void ColumnBrowser::open(const std::shared_ptr<ItemList>& items) {
  auto column = new Column(this, items);
  GetSizer()->Add(column, wxSizerFlags().Expand());
  columns_.push_back(column);
}
/***********************************************************************//**
	@brief 
***************************************************************************/
void ColumnBrowser::close() {
  FK_ASSERT(!columns_.empty());
  columns_.back()->Destroy();
  columns_.pop_back();
}
/***********************************************************************//**
	@brief コンストラクタ
***************************************************************************/
ColumnBrowser::Column::Column(wxWindow* parent, 
                              const std::shared_ptr<ItemList>& items)
  : super(parent, wxID_ANY, wxDefaultPosition, wxSize(200, 0)), 
    items_(items)
{
  AppendIconTextColumn("Name");
  for(auto& item : *items) {
    wxVector<wxVariant> values;
    values.push_back(wxVariant(wxDataViewIconText(item->getName(), 
                                                  wxArtProvider::GetIcon(wxART_FOLDER))));
    AppendItem(values);
  }
}
/***********************************************************************//**
	@brief 
***************************************************************************/
ColumnBrowser::Item::Item(const wxString& name)
  : name_(name)
{
}
/***********************************************************************//**
	$Id$
***************************************************************************/
}
}
