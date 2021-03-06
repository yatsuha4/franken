﻿/***********************************************************************//**
	@file
***************************************************************************/
#include "fk/fk.hpp"
/***********************************************************************//**
	@brief wxWidgets
***************************************************************************/
#include "wx/artprov.h"
#include "wx/aui/auibook.h"
#include "wx/aui/framemanager.h"
#include "wx/dataview.h"
#include "wx/dir.h"
#include "wx/filectrl.h"
#include "wx/propgrid/propgrid.h"
#include "wx/stdpaths.h"
/***********************************************************************//**
	@brief 
***************************************************************************/
#include <fbxsdk.h>
/***********************************************************************//**
	@brief 
***************************************************************************/
namespace franken {
namespace asset {
FK_DECLARE_CLASS(AssetBrowser);
}
using namespace asset;

namespace file {
namespace fbx {
FK_DECLARE_CLASS(Importer);
}
}
using namespace file;

namespace gui {
FK_DECLARE_CLASS(Canvas);
}
using namespace gui;

namespace inspector {
FK_DECLARE_CLASS(Inspector);
}
using namespace inspector;

namespace main {
FK_DECLARE_CLASS(Application);
FK_DECLARE_CLASS(ColumnBrowser);
FK_DECLARE_CLASS(Component);
FK_DECLARE_CLASS(Config);
FK_DECLARE_CLASS(Context);
FK_DECLARE_CLASS(MainFrame);
FK_DECLARE_CLASS(Object);
FK_DECLARE_CLASS(Property);
using ContextHolder = fk::ContextHolder<Context>;
}
using namespace main;

namespace outliner {
FK_DECLARE_CLASS(Outliner);
}
using namespace outliner;
}
/***********************************************************************//**
	$Id$
***************************************************************************/
