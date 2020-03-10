﻿/***********************************************************************//**
	@file
***************************************************************************/
#pragma once

namespace fk::vm {
/***********************************************************************//**
	@brief 
***************************************************************************/
class Code {
 public:
  struct Opecode {
    uint16_t opecode;
    int16_t operand;
  }
};
}