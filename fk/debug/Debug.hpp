﻿/***********************************************************************//**
	@file
***************************************************************************/
#pragma once

#include "fk/debug/Logger.hpp"
#include "fk/util/String.hpp"
/***********************************************************************//**
	@brief デバッグ用マクロ
***************************************************************************/
#if !defined(FK_MASTER)
#define FK_LOG(level, ...)                                              \
  ::fk::Debug::Log(level,                                               \
                   ::fk::util::String::Format(__VA_ARGS__).c_str(),     \
                   __FILE__, __LINE__)
#else
#define FK_LOG(...)
#endif

#define FK_PRINTF(...)                                  \
  FK_LOG(::fk::Logger::Level::Debug, __VA_ARGS__)

#define FK_INFO(...)                                  \
  FK_LOG(::fk::Logger::Level::Info, __VA_ARGS__)

#define FK_WARNING(...)                                  \
  FK_LOG(::fk::Logger::Level::Warning, __VA_ARGS__)

#define FK_ERROR(...)                                  \
  FK_LOG(::fk::Logger::Level::Error, __VA_ARGS__)

#define FK_FATAL(...)                                  \
  FK_LOG(::fk::Logger::Level::Fatal, __VA_ARGS__)

#define FK_ASSERT(e)                            \
  if(!(e)) {                                    \
  FK_FATAL("[ASSERT]%s", #e);                   \
  }

#define FK_DUMP(value) \
  FK_PRINTF("%s = %s", #value, fk::String::From(value).c_str())

namespace fk {
namespace debug {
/***********************************************************************//**
	@brief 
***************************************************************************/
class Debug {
 private:
  static LoggerPtr Logger_;

 public:
  static void SetLogger(const LoggerPtr& logger);
  static Logger& GetLogger();
  static void Log(Logger::Level level, const std::string& message, 
                  const char* filename, int line);

 private:
  static void Suspend();
};
/***********************************************************************//**
	$Id$
***************************************************************************/
}
}
