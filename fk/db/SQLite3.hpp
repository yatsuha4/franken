/***********************************************************************//**
	@file
***************************************************************************/
#pragma once

#include <sqlite3.h>

namespace fk::db {
/***********************************************************************//**
	@brief SQLite3
***************************************************************************/
class SQLite3 {
 public:
  FK_DECLARE_CLASS(Statement);

 private:
  sqlite3* db_;

 public:
  SQLite3();
  ~SQLite3();

  bool open(const std::filesystem::path& path, 
            int flag = SQLITE_OPEN_READONLY);
  bool isOpen() const;
  void close();

  StatementPtr prepare(const std::string& query);
  bool step(const Statement& statement);
  StatementPtr execute(const std::string& query);

  int getLastInsertRowId() const;
  void setLastInsertRowId(int id);
};
/***********************************************************************//**
	@brief 
***************************************************************************/
class SQLite3::Statement {
 private:
  sqlite3_stmt* stmt_;

 public:
  Statement(sqlite3_stmt* stmt);
  ~Statement();

  FK_GETTER(Stmt, stmt_);

  void bind(size_t index, int value);
  void bind(size_t index, double value);
  void bind(size_t index, const std::string& value);

  void get(size_t index, int& value);
  void get(size_t index, double& value);
  void get(size_t index, std::string& value);

  template <class T>
  T get(size_t index) {
    T value;
    get(index, value);
    return value;
  }
};
}
