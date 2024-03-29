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

#include <layout/frames.h>
#include <layout/frametypes.h>

namespace Layout
{
	//! Horizontal flow frame (xul:hbox)
	class HFrame : public Frame
	{
	public:
		HFrame() { frameStyle.layout.flex = 1; }
		virtual ~HFrame() {}

		virtual bool Layout();
		virtual const char* GetName() { return "hbox"; }
		virtual Frame* Create() { return new HFrame(); }
		FRAMETYPE(HBOX, Frame)
	};

	//! Vertical flow frame (xul:vbox)
	class VFrame : public Frame
	{
	public:
		VFrame() { frameStyle.layout.flex = 1; }
		virtual ~VFrame() {}

		virtual bool Layout();
		virtual const char* GetName() { return "vbox"; }
		virtual Frame* Create() { return new VFrame(); }
		FRAMETYPE(VBOX, Frame)
	};

	//! xul:box
	class Box : public HFrame
	{
	public:
		Box() { frameStyle.layout.flex = 0; }
		virtual const char* GetName() { return "box"; }
		virtual Frame* Create() { return new Box(); }
		FRAMETYPE(BOX, Frame)
	};

}