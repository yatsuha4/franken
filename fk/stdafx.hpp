/***********************************************************************//**
	@file
***************************************************************************/
#if defined(__ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__)
#define FK_PLATFORM "mac"
#define FK_PLATFORM_MAC
#define FK_PLATFORM_APPLE
#define FK_PLATFORM_POSIX
#define FK_WITH_WX
#define FK_WITH_GL

#else
#error "not support platform"
#endif
/***********************************************************************//**
	@brief 
***************************************************************************/
#include <memory>
#include <vector>
#include <sstream>
/***********************************************************************//**
	@brief wxWidgets
***************************************************************************/
#if defined(FK_WITH_WX)
#if defined(FK_PLATFORM_MAC)
#define _FILE_OFFSET_BITS 64
#define __WXMAC__
#define __WXOSX__
#define __WXOSX_COCOA__
#endif
#include "wx/wx.h"
#endif
/***********************************************************************//**
	@brief マクロ
***************************************************************************/
#define FK_SETTER(name, var) \
  auto set##name(const decltype(var)& value) -> decltype(*this)& { \
    var = value; \
    return *this; \
  }

#define FK_GETTER(name, var)                    \
  const decltype(var)& get##name() const {      \
    return var;                                 \
  }

#define FK_REFER(name, var)                     \
  FK_GETTER(name, var);                         \
  decltype(var)& get##name() {                  \
    return var;                                 \
  }

#define FK_ACCESSOR(name, var)                  \
  FK_SETTER(name, var);                         \
  FK_REFER(name, var);

#define FK_BIT_SETTER(name, var, index)                                 \
  auto set##name(bool value) -> decltype(*this)& {                      \
                                                  var.set(index, value); \
                                                  return *this;         \
  }

#define FK_BIT_GETTER(name, var, index)         \
  bool is##name() const {                       \
    return var.test(index);                     \
  }

#define FK_BIT_ACCESSOR(name, var, index)       \
  FK_BIT_SETTER(name, var, index);              \
  FK_BIT_GETTER(name, var, index)

#define FK_CAN_SETTER(name, var, index)                                 \
  auto setCan##name(bool value) -> decltype(*this)& {                   \
                                                     var.set(index, value); \
                                                     return *this;      \
  }

#define FK_CAN_GETTER(name, var, index)         \
  bool can##name() const {                      \
    return var.test(index);                     \
  }

#define FK_CAN_ACCESSOR(name, var, index)       \
  FK_CAN_SETTER(name, var, index);              \
  FK_CAN_GETTER(name, var, index)

#define FK_DECLARE_CLASS(klass)                                 \
  class klass;                                                  \
  using klass##Ptr = std::shared_ptr<klass>;                    \
  using Const##klass##Ptr = std::shared_ptr<const klass>;
/***********************************************************************//**
	@brief 
***************************************************************************/
namespace fk {
namespace debug {
FK_DECLARE_CLASS(Debug);
FK_DECLARE_CLASS(Logger);
}
using namespace debug;

namespace framework {
FK_DECLARE_CLASS(Behaviour);
FK_DECLARE_CLASS(Component);
FK_DECLARE_CLASS(Context);
FK_DECLARE_CLASS(Object);
}
using namespace framework;

namespace render {
FK_DECLARE_CLASS(RenderParam);
FK_DECLARE_CLASS(Renderer);
}
using namespace render;

namespace util {
FK_DECLARE_CLASS(String);
}
using namespace util;
}
/***********************************************************************//**
	@brief 
***************************************************************************/
#include "fk/debug/Debug.hpp"
/***********************************************************************//**
	$Id$
***************************************************************************/
