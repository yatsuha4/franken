﻿/***********************************************************************//**
	@file
***************************************************************************/
#pragma once

namespace fk {
namespace debug {
/***********************************************************************//**
	@brief ログ出力
***************************************************************************/
class Logger {
 public:
  enum class Level {
    Debug, 
    Info, 
    Warning, 
    Error, 
    Fatal
  };

 private:
  Level level_;
  std::mutex mutex_;

 public:
  Logger() = default;
  virtual ~Logger() = default;

  void log(Level level, const std::string& message);

 protected:
  virtual void onLog(const std::string& message);
};
/***********************************************************************//**
	$Id$
***************************************************************************/
}
}
