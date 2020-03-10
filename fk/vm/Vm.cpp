﻿/***********************************************************************//**
	@file
***************************************************************************/
#include "fk/vm/Frame.hpp"
#include "fk/vm/Vm.hpp"

namespace fk::vm {
/***********************************************************************//**
	@brief コンストラクタ
***************************************************************************/
Vm::Vm(const CodePtr& code)
  : code_(code)
{
}
/***********************************************************************//**
	@brief デストラクタ
***************************************************************************/
Vm::~Vm() {
}
/***********************************************************************//**
	@brief 
***************************************************************************/
Vm& Vm::push(const std::any& value) {
  stack_.push(value);
  return *this;
}
/***********************************************************************//**
	@brief 
***************************************************************************/
std::any Vm::pop() {
  auto value = stack_.top();
  stack_.pop();
  return value;
}
/***********************************************************************//**
	@brief 
***************************************************************************/
FramePtr Vm::createFrame(symbol_t klass, symbol_t func) const {
  const Code* pc = nullptr;
  return std::make_shared<Frame>(shared_from_this(), pc, frame_);
}
}