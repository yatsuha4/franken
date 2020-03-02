/***********************************************************************//**
	@file
***************************************************************************/
#include "fk/db/SQLite3.hpp"

namespace fk::db {
/***********************************************************************//**
	@brief デフォルトコンストラクタ
***************************************************************************/
SQLite3::SQLite3()
  : db_(nullptr)
{
}
/***********************************************************************//**
	@brief デストラクタ
***************************************************************************/
SQLite3::~SQLite3() {
  close();
}
/***********************************************************************//**
	@brief 
***************************************************************************/
bool SQLite3::open(const std::filesystem::path& path, int flag) {
  close();
  return sqlite3_open_v2(path.c_str(), &db_, flag, nullptr) == SQLITE_OK;
}
/***********************************************************************//**
	@brief 
***************************************************************************/
bool SQLite3::isOpen() const {
  return db_ != nullptr;
}
/***********************************************************************//**
	@brief 
***************************************************************************/
void SQLite3::close() {
  if(isOpen()) {
    sqlite3_close(db_);
  }
}
/***********************************************************************//**
	@brief 
***************************************************************************/
SQLite3::StatementPtr SQLite3::prepare(const std::string& query) {
  if(isOpen()) {
    sqlite3_stmt* stmt;
    if(sqlite3_prepare(db_, query.c_str(), -1, &stmt, 0) == SQLITE_OK) {
      return std::make_shared<Statement>(stmt);
    }
  }
  return nullptr;
}
/***********************************************************************//**
	@brief 
***************************************************************************/
bool SQLite3::step(const Statement& statement) {
  return sqlite3_step(statement.getStmt()) == SQLITE_ROW;
}
/***********************************************************************//**
	@brief 
***************************************************************************/
SQLite3::StatementPtr SQLite3::execute(const std::string& query) {
  if(auto statement = prepare(query)) {
    if(sqlite3_step(statement->getStmt()) == SQLITE_DONE) {
      return statement;
    }
  }
  return nullptr;
}
/***********************************************************************//**
	@brief 
***************************************************************************/
int SQLite3::getLastInsertRowId() const {
  FK_ASSERT(isOpen());
  return static_cast<int>(sqlite3_last_insert_rowid(db_));
}
/***********************************************************************//**
	@brief コンストラクタ
***************************************************************************/
SQLite3::Statement::Statement(sqlite3_stmt* stmt)
  : stmt_(stmt)
{
}
/***********************************************************************//**
	@brief デストラクタ
***************************************************************************/
SQLite3::Statement::~Statement() {
  sqlite3_finalize(stmt_);
}
/***********************************************************************//**
	@brief 
***************************************************************************/
void SQLite3::Statement::bind(size_t index, int value) {
  sqlite3_bind_int(getStmt(), static_cast<int>(index), value);
}
/***********************************************************************//**
	@brief 
***************************************************************************/
void SQLite3::Statement::bind(size_t index, double value) {
  sqlite3_bind_double(getStmt(), static_cast<int>(index), value);
}
/***********************************************************************//**
	@brief 
***************************************************************************/
void SQLite3::Statement::bind(size_t index, const std::string& value) {
  sqlite3_bind_text(getStmt(), static_cast<int>(index), value.c_str(), 
                    static_cast<int>(value.length()), SQLITE_TRANSIENT);
}
/***********************************************************************//**
	@brief 
***************************************************************************/
void SQLite3::Statement::get(size_t index, int& value) {
  value = sqlite3_column_int(getStmt(), static_cast<int>(index));
}
/***********************************************************************//**
	@brief 
***************************************************************************/
void SQLite3::Statement::get(size_t index, double& value) {
  value = sqlite3_column_double(getStmt(), static_cast<int>(index));
}
/***********************************************************************//**
	@brief 
***************************************************************************/
void SQLite3::Statement::get(size_t index, std::string& value) {
  if(auto text = sqlite3_column_text(getStmt(), static_cast<int>(index))) {
    value.assign(reinterpret_cast<const char*>(text));
  }
  else {
    value.clear();
  }
}
}
