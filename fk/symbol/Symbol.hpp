/***********************************************************************//**
	@file
***************************************************************************/
#pragma once

namespace fk::symbol {
/***********************************************************************//**
	@brief 
***************************************************************************/
class Symbol {
 public:
  static constexpr symbol_t Get(const char* label) {
    symbol_t symbol = 0;
    if(!Get(label, symbol)) {
      std::abort();
    }
    return symbol;
  }

  static constexpr bool Get(const char* label, symbol_t& symbol) {
    const char* SYMBOLS[] = {
      "NULL", 
      "APPLE", 
      "BANANA", 
      "CHERRY"
    };
    auto size = std::size(SYMBOLS);
    if(auto index = GetIndex(label, SYMBOLS, size); index < size) {
      symbol = static_cast<symbol_t>(index);
      return true;
    }
    return false;
  }

 protected:
  static constexpr size_t GetIndex(const char* label, const char* labels[], size_t n) {
    for(size_t i = 0; i < n; i++) {
      if(StrCmp(label, labels[i])) {
        return i;
      }
    }
    return n;
  }

  static constexpr bool StrCmp(const char* lhs, const char* rhs) {
    for(size_t i = 0; lhs[i] == rhs[i]; i++) {
      if(lhs[i] == '\0') {
        return true;
      }
    }
    return false;
  }
};
}
