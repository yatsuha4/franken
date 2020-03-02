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
  auto database = std::make_unique<SQLite3>();
  if(database->open(path)) {
    databases_.push_back(std::move(database));
    return true;
  }
  return false;
}
/***********************************************************************//**
	@brief 
***************************************************************************/
void Symbolizer::close() {
  for(auto& database : databases_) {
    database->close();
  }
  databases_.clear();
}
/***********************************************************************//**
	@brief 
***************************************************************************/
symbol_t Symbolizer::getSymbol(const std::string& label) {
  for(auto& database : databases_) {
    symbol_t symbol;
    if(findSymbol(*database, label, symbol)) {
      return symbol;
    }
  }
  return 0;
}
/***********************************************************************//**
	@brief 
***************************************************************************/
std::string Symbolizer::getLabel(symbol_t symbol) {
  for(auto& database : databases_) {
    std::string label;
    if(findLabel(*database, symbol, label)) {
      return label;
    }
  }
  return std::string();
}
/***********************************************************************//**
	@brief 
***************************************************************************/
bool Symbolizer::findSymbol(SQLite3& database, const std::string& label, 
                            symbol_t& symbol) {
  std::ostringstream query;
  query << "select symbol from symbol where label = '" << label << "'";
  if(auto statement = database.execute(query.str())) {
    symbol = static_cast<symbol_t>(statement->get<int>(0));
    return true;
  }
  return false;
}
/***********************************************************************//**
	@brief 
***************************************************************************/
bool Symbolizer::findLabel(SQLite3& database, symbol_t symbol, 
                           std::string& label) {
  std::ostringstream query;
  query << "select label from symbol where symbol = " << symbol;
  if(auto statement = database.execute(query.str())) {
    label = statement->get<std::string>(0);
    return true;
  }
  return false;
}
/***********************************************************************//**
	@brief 
***************************************************************************/
symbol_t Symbolizer::appendSymbol(SQLite3& database, 
                                  const std::string& label) {
  std::ostringstream query;
  query << "insert into symbol (label) values('" << label << "')";
  if(!database.execute(query.str())) {
    createTable(database);
    if(!database.execute(query.str())) {
    }
  }
  return static_cast<symbol_t>(database.getLastInsertRowId());
}
/***********************************************************************//**
	@brief 
***************************************************************************/
bool Symbolizer::createTable(SQLite3& database) {
  if(!database.execute("create table symbol ("
                       "symbol integer primary key autoincrement, "
                       "label text unique not null)")) {
    int a = 0;
    switch(a) {
    case Symbol::Get("APPLE"):
      break;
    default:
      break;
    }
  }
  return false;
}
}
