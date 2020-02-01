/***********************************************************************//**
	@file
***************************************************************************/
#include "fk/debug/Logger.hpp"

namespace fk {
namespace debug {
/***********************************************************************//**
	@brief 
***************************************************************************/
void Logger::log(Level level, const std::string& message) {
  static const char* LEVELS[] = {
    "DEBUG", 
    "INFO", 
    "WARNING", 
    "ERROR", 
    "FATAL"
  };
  if(level >= level_) {
    std::stringstream stream;
    stream << "[" << LEVELS[size_t(level)] << "]" << message;
    {
      std::lock_guard<std::mutex> lock(mutex_);
      onLog(stream.str());
    }
  }
}
/***********************************************************************//**
	@brief 
***************************************************************************/
void Logger::onLog(const std::string& message) {
  std::cerr << message << std::endl;
}
/***********************************************************************//**
	$Id$
***************************************************************************/
}
}
