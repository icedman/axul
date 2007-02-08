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

#include "events.h"

namespace Events
{
	Event::Event(int eid, Frame *pFrame)
	{
		Attach(eid, pFrame);
	}

	bool Event::Attach(int eid, Frame *pFrame)
	{
		eventId = eid;
		frame = pFrame;
		return true;
	}

	bool EventManager::AddListener(Event* pEvent)
	{
		return Push(pEvent);
	}

	bool EventManager::RemoveListener(Event* pEvent)
	{
		return Remove(pEvent);
	}

	bool MouseEvents::OnMouseEvent(int eventId, int button, int x, int y)
	{
		Event *e = GetFirst();
		while(e)
		{
			Frame *f = e->frame;
			Rect r;
			f->GetBorderRect(&r);
			Point p(x,y);
			if (r.Contains(p))
			{
				f->OnEvent(eventId, (void*)&p);
			}
			e = e->next;
		}
		return true;
	}
}
