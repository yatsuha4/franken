﻿/***********************************************************************//**
	@file
***************************************************************************/
#include "fk/debug/Debug.hpp"

namespace fk {
namespace debug {
LoggerPtr Debug::Logger_;
/***********************************************************************//**
	@brief 
***************************************************************************/
void Debug::SetLogger(const LoggerPtr& logger) {
  Logger_ = logger;
}
/***********************************************************************//**
	@brief 
***************************************************************************/
Logger& Debug::GetLogger() {
  if(!Logger_) {
    SetLogger(std::make_shared<Logger>());
  }
  return *Logger_;
}
/***********************************************************************//**
	@brief 
***************************************************************************/
void Debug::Log(Logger::Level level, const std::string& message, 
                const char* filename, int line) {
  std::stringstream stream;
  stream << message;
  GetLogger().log(level, stream.str());
  if(level >= Logger::Level::Fatal) {
    Suspend();
  }
}
/***********************************************************************//**
	@brief 
***************************************************************************/
void Debug::Suspend() {
#if defined(FK_PLATFORM_WINDOWS)
  DebugBreak();
#else
  __builtin_trap();
#endif
}
/***********************************************************************//**
	$Id$
***************************************************************************/
}
}
