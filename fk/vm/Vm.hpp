/***********************************************************************//**
	@file
***************************************************************************/
#pragma once

namespace fk::vm {
/***********************************************************************//**
	@brief VM
***************************************************************************/
class Vm
  : public std::enable_shared_from_this<Vm>
{
 private:
  std::stack<std::any> stack_;
  CodePtr code_;
  FramePtr frame_;

 public:
  Vm(const CodePtr& code);
  virtual ~Vm();

  Vm& push(const std::any& value);
  std::any pop();

  FramePtr createFrame(symbol_t klass, symbol_t func) const;

 protected:
  virtual std::optional<std::any>
  onTrap(symbol_t klass, symbol_t method, const std::vector<std::any>& args);
};
}
