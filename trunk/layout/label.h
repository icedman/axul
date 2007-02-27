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
#include <layout/layout.h>

namespace Layout
{
	class Label : public HFrame
	{
	public:
		Label();
		virtual const char* GetName() { return "label"; }
		virtual Frame* Create() { return new Label(); }
		FRAMETYPE(LABEL, Frame)

		virtual bool Prelayout();
		virtual Dom::DOMString* GetText();
		virtual void Draw(Render::Rasterizer *render);

		virtual bool RegisterEventListeners();
		virtual void HandleEvent(Dom::Event *evt);
	};
}
