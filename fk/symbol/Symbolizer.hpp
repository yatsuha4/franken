/***********************************************************************//**
	@file
***************************************************************************/
#pragma once

namespace fk::symbol {
/***********************************************************************//**
	@brief シンボライザー
***************************************************************************/
class Symbolizer {
 public:
  class Error {};

  static const symbol_t SYMBOL_USER_TOP = 0x10000;

 private:
  std::unique_ptr<SQLite3> database_;

 public:
  Symbolizer() = default;
  virtual ~Symbolizer() = default;

  bool open(const std::filesystem::path& path);
  void close();

  virtual symbol_t getSymbol(const std::string& label);

 private:
  bool findSymbol(const std::string& label, symbol_t& symbol);
  bool appendSymbol(const std::string& label, symbol_t& symbol);
  bool createTable();
};
}
