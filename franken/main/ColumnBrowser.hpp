﻿/***********************************************************************//**
	@file
***************************************************************************/
#pragma once

namespace franken {
namespace main {
/***********************************************************************//**
	@brief カラムブラウザ
***************************************************************************/
class ColumnBrowser
  : public wxPanel
{
  using super = wxPanel;

 public:
  FK_DECLARE_CLASS(Column);
  FK_DECLARE_CLASS(Item);
  using ItemList = std::vector<ItemPtr>;

 private:
  std::vector<Column*> columns_;

 public:
  ColumnBrowser(wxWindow* parent);
  ~ColumnBrowser() override = default;

  void open(const std::shared_ptr<ItemList>& items);
  void close();

 protected:
  virtual void onSelect(const ItemPtr& item) {}
};
/***********************************************************************//**
	@brief 
***************************************************************************/
class ColumnBrowser::Column
  : public wxDataViewListCtrl
{
  using super = wxDataViewListCtrl;

 private:
  std::shared_ptr<ItemList> items_;

 public:
  Column(wxWindow* parent, const std::shared_ptr<ItemList>& items);
  ~Column() override = default;
};
/***********************************************************************//**
	@brief 
***************************************************************************/
class ColumnBrowser::Item {
 private:
  wxString name_;

 public:
  Item(const wxString& name);
  virtual ~Item() = default;

  FK_GETTER(Name, name_);
};
/***********************************************************************//**
	$Id$
***************************************************************************/
}
}
