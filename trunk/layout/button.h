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

#include <layout/layout.h>
#include <layout/frametypes.h>
#include <events/events.h>

using namespace Events;

namespace Layout
{
	class Button : public HFrame
	{
	public:
		Button();

		virtual const char* GetName() { return "button"; }
		virtual Frame* Create() { return new Button(); }
		FRAMETYPE(BUTTON, HFrame)

		virtual bool Prelayout();
		virtual void Draw(Render::Rasterizer *render);
		virtual Dom::DOMString* GetText();

		virtual bool OnEvent(int eid, void *pp);
		virtual bool RegisterEvents(EventManager *manager);
	};

}