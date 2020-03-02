/***********************************************************************//**
	@file
***************************************************************************/
#include "fk/db/SQLite3.hpp"
#include "fk/symbol/Symbol.hpp"
#include "fk/symbol/Symbolizer.hpp"

namespace fk::symbol {
/***********************************************************************//**
	@brief 
***************************************************************************/
bool Symbolizer::open(const std::filesystem::path& path) {
  close();
  auto database = std::make_unique<SQLite3>();
  if(database->open(path)) {
    database_ = std::move(database);
    return true;
  }
  return false;
}
/***********************************************************************//**
	@brief 
***************************************************************************/
void Symbolizer::close() {
  database_.reset();
}
/***********************************************************************//**
	@brief 
***************************************************************************/
symbol_t Symbolizer::getSymbol(const std::string& label) {
  symbol_t symbol = 0;
  if(!Symbol::Get(label.c_str(), symbol)) {
    if(!findSymbol(label, symbol)) {
      if(!appendSymbol(label, symbol)) {
        throw Error();
      }
    }
  }
  return symbol;
}
/***********************************************************************//**
	@brief 
***************************************************************************/
bool Symbolizer::findSymbol(const std::string& label, symbol_t& symbol) {
  std::ostringstream query;
  query << "select symbol from symbol where label = '" << label << "'";
  if(auto statement = database_->execute(query.str())) {
    symbol = static_cast<symbol_t>(statement->get<int>(0));
    return true;
  }
  return false;
}
/***********************************************************************//**
	@brief 
***************************************************************************/
bool Symbolizer::appendSymbol(const std::string& label, symbol_t& symbol) {
  std::ostringstream query;
  query << "insert into symbol (label) values('" << label << "')";
  if(!database_->execute(query.str())) {
    if(!createTable() || !database_->execute(query.str())) {
      return false;
    }
  }
  symbol = static_cast<symbol_t>(database_->getLastInsertRowId());
  return true;
}
/***********************************************************************//**
	@brief 
***************************************************************************/
bool Symbolizer::createTable() {
  if(database_->execute("create table symbol ("
                        "symbol integer primary key autoincrement, "
                        "label text unique not null)")) {
    database_->setLastInsertRowId(SYMBOL_USER_TOP);
    return true;
  }
  return false;
}
}
