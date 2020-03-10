/***********************************************************************//**
	@file
***************************************************************************/
#pragma once

namespace fk::util {
/***********************************************************************//**
	@brief 
***************************************************************************/
template <class T, T max>
class BitSet
  : public std::bitset<static_cast<size_t>(max)>
{
  using super = std::bitset<static_cast<size_t>(max)>;

 public:
  BitSet() = default;
  ~BitSet() = default;

  BitSet& set(const T& index, bool value = true) {
    super::set(static_cast<size_t>(index), value);
    return *this;
  }

  bool test(const T& index) const {
    return super::test(static_cast<size_t>(index));
  }
};
/***********************************************************************//**
	$Id$
***************************************************************************/
}
