/***********************************************************************//**
	@file
***************************************************************************/
#pragma once

namespace fk {
namespace util {
/***********************************************************************//**
	@brief 文字列ユーティリティー
***************************************************************************/
class String {
 public:
  static std::string Format(const char* text) {
    return std::string(text);
  }

  template <class... Args>
  static std::string Format(const char* format, const Args&... args) {
    std::vector<char> buffer(128);
    while(std::snprintf(buffer.data(), buffer.size(), format, args...) >= 
          static_cast<int>(buffer.size())) {
      buffer.resize(buffer.size() * 2);
    }
    return std::string(buffer.data());
  }

  template <class T>
  static std::string From(const T& value) {
    std::ostringstream stream;
    stream << value;
    return stream.str();
  }
};
/***********************************************************************//**
	$Id$
***************************************************************************/
}
}
