/***********************************************************************//**
	@file
***************************************************************************/
#pragma once

namespace fk::vm {
/***********************************************************************//**
	@brief 関数フレーム
***************************************************************************/
class Frame {
 private:
  VmPtr vm_;
  const Code* pc_;
  FramePtr parent_;
  std::vector<std::any> localVars_;

 public:
  Frame(const VmPtr& vm, const Code* pc, const FramePtr& parent = nullptr);
  ~Frame();

  Frame& setLocalVar(size_t index, const std::any& value);
};
}
