/***********************************************************************//**
	@file
***************************************************************************/
#pragma once

#include "fk/resource/Resource.hpp"
#include "fk/util/BitSet.hpp"

namespace fk::resource {
/***********************************************************************//**
	@brief 
***************************************************************************/
class MemoryResource
  : public Resource
{
 private:
  enum class Flag {
    Ready, 
    Max
  };

 private:
  std::vector<uint8_t> data_;
  BitSet<Flag, Flag::Max> flag_;

 public:
  MemoryResource() = default;
  ~MemoryResource() override = default;

  void* allocate(size_t size);
  void clear();

  void setReady(bool value = true) {
    flag_.set(Flag::Ready, value);
  }

  bool isReady() const override {
    return flag_.test(Flag::Ready);
  }

  const void* getData() const override {
    return isReady() ? static_cast<const void*>(data_.data()) : nullptr;
  }

  size_t getSize() const override {
    return data_.size();
  }
};
/***********************************************************************//**
	$Id$
***************************************************************************/
}
