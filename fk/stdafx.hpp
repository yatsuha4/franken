﻿/***********************************************************************//**
	@file
***************************************************************************/
#if defined(__ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__)
#  define FK_PLATFORM "mac"
#  define FK_PLATFORM_MAC
#  define FK_PLATFORM_APPLE
#  define FK_PLATFORM_POSIX
#  define FK_WITH_WX
#  define FK_WITH_GL
#elif defined(WIN32)
#  define FK_PLATFORM "win32"
#  define FK_PLATFORM_WIN32
#  define FK_PLATFORM_WINDOWS
#  define FK_WITH_WX
#  define FK_WITH_GL
#  define _CRT_SECURE_NO_WARNINGS
#else
#  error "not support platform"
#endif
/***********************************************************************//**
	@brief 
***************************************************************************/
#include <array>
#include <bitset>
#include <filesystem>
#include <fstream>
#include <memory>
#include <mutex>
#include <sstream>
#include <stack>
#include <vector>
/***********************************************************************//**
	@brief OpenGL
***************************************************************************/
#if defined(FK_WITH_GL)
#  if defined(FK_PLATFORM_MAC)
#    define GL_SILENCE_DEPRECATION
#    define GL_DO_NOT_WARN_IF_MULTI_GL_VERSION_HEADERS_INCLUDED
#    include <OpenGL/gl3.h>
#  elif defined(FK_PLATFORM_WINDOWS)
#    include <GL/glew.h>
#  endif
#endif
/***********************************************************************//**
	@brief wxWidgets
***************************************************************************/
#if defined(FK_WITH_WX)
#  if defined(FK_PLATFORM_MAC)
#    define _FILE_OFFSET_BITS 64
#    define __WXMAC__
#    define __WXOSX__
#    define __WXOSX_COCOA__
#  endif
#  include "wx/wx.h"
#  if defined(FK_WITH_GL)
#    include "wx/glcanvas.h"
#  endif
#endif
/***********************************************************************//**
	@brief GLM
***************************************************************************/
#include "glm/glm.hpp"
#include "glm/ext.hpp"
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

#define FK_BIT_SETTER(name, var, index)                 \
  auto set##name(bool value) -> decltype(*this)& {      \
    var.set(static_cast<size_t>(index), value);         \
    return *this;                                       \
  }

#define FK_BIT_GETTER(name, var, index)                 \
  bool is##name() const {                               \
    return var.test(static_cast<size_t>(index));        \
  }

#define FK_BIT_ACCESSOR(name, var, index)       \
  FK_BIT_SETTER(name, var, index);              \
  FK_BIT_GETTER(name, var, index)

#define FK_CAN_SETTER(name, var, index)                 \
  auto setCan##name(bool value) -> decltype(*this)& {   \
    var.set(static_cast<size_t>(index), value);         \
    return *this;                                       \
  }

#define FK_CAN_GETTER(name, var, index)                 \
  bool can##name() const {                              \
    return var.test(static_cast<size_t>(index));        \
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
using symbol_t = uint32_t;

namespace camera {
FK_DECLARE_CLASS(Camera);
}
using namespace camera;

namespace db {
FK_DECLARE_CLASS(SQLite3);
}
using namespace db;

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

namespace math {
}
using namespace math;

namespace model {
FK_DECLARE_CLASS(Geometry);
FK_DECLARE_CLASS(Mesh);
FK_DECLARE_CLASS(Model);
FK_DECLARE_CLASS(Vertex);
}
using namespace model;

namespace platform {
}
using namespace platform;

namespace render {
FK_DECLARE_CLASS(Material);
FK_DECLARE_CLASS(RenderParam);
FK_DECLARE_CLASS(Renderable);
FK_DECLARE_CLASS(Renderer);
FK_DECLARE_CLASS(Shader);
FK_DECLARE_CLASS(ShaderProgram);
}
using namespace render;

namespace resource {
FK_DECLARE_CLASS(FileResource);
FK_DECLARE_CLASS(Resource);
FK_DECLARE_CLASS(ResourceManager);
}
using namespace resource;

namespace symbol {
FK_DECLARE_CLASS(Symbolizer);
}
using namespace symbol;

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
