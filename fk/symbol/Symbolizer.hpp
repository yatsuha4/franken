/***********************************************************************//**
	@file
***************************************************************************/
#pragma once

namespace fk::symbol {
/***********************************************************************//**
	@brief シンボライザー
***************************************************************************/
class Symbolizer {
 private:
  std::vector<std::unique_ptr<SQLite3>> databases_;

 public:
  Symbolizer() = default;
  ~Symbolizer() = default;

  bool open(const std::filesystem::path& path);
  void close();

  symbol_t getSymbol(const std::string& label);
  std::string getLabel(symbol_t symbol);

 private:
  bool findSymbol(SQLite3& database, const std::string& label, 
                  symbol_t& symbol);
  bool findLabel(SQLite3& database, symbol_t symbol, std::string& label);
  symbol_t appendSymbol(SQLite3& database, const std::string& label);
  bool createTable(SQLite3& database);
};
}
