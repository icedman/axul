/*
Version: MPL 1.1/GPL 2.0/LGPL 2.1

The contents of this file are subject to the Mozilla Public License Version
1.1 (the "License"); you may not use this file except in compliance with
the License. You may obtain a copy of the License at
http://www.mozilla.org/MPL/

Software distributed under the License is distributed on an "AS IS" basis,
WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
for the specific language governing rights and limitations under the
License.

Copyright 2007
Marvin Sanchez
code.google.com/p/ashlar
*/

#pragma once

#include <dom/document.h>
#include <dom/docbuilder.h>
#include <dom/stylesheet.h>
#include <layout/windowframe.h>
#include <layout/framebuilder.h>
#include <render/resources.h>
#include <script/scriptengine.h>

using namespace Dom;
using namespace Layout;
using namespace Render;
using namespace Script;

namespace Ash
{
	//! Widget class
	class Widget : public Frame
	{
	public:

		Widget();
		virtual ~Widget();

		FRAMETYPE(WIDGET, Frame)

		//! Loads widget from an xul file
		bool Load(const char* filename);
		virtual void Free();

		StyleSheet* GetStyleSheet() { return &styleSheet; }
		DOMDocument* GetDocument() { return (DOMDocument*)element; }
		ResourceManager* GetResources() { return resources; }
		ScriptEngine* GetScriptEngine() { return &scriptEngine; }

	private:

		StyleSheet			styleSheet;
		ResourceManager	*resources;
		ScriptEngine		scriptEngine;
	};

}