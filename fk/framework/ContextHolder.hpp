﻿/***********************************************************************//**
	@file
***************************************************************************/
#pragma once

namespace fk {
namespace framework {
/***********************************************************************//**
	@brief コンテキストを保持する
***************************************************************************/
template <class T = Context>
class ContextHolder {
 private:
  std::weak_ptr<T> context_;

 public:
  ContextHolder(const std::shared_ptr<T>& context)
    : context_(context)
  {
  }
  ~ContextHolder() = default;

  std::shared_ptr<T> getContext() const {
    return context_.lock();
  }
};
/***********************************************************************//**
	$Id$
***************************************************************************/
}
}
