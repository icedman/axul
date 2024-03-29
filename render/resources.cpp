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

#include <render/resources.h>
#include <render/imageRes.h>
#include <dom/safenode.h>

#include <cairo.h>

namespace Render
{
	Resource::Resource(DOMString* n, DOMString* src, int t, int i)
	{
		name = *n;
		type = t;
		id = i;

		// do something with source
	}

	Resource::~Resource()
	{
	}

	void Resource::Dump()
	{
		printf("res: #%d %d %s\n", GetId(), type, name.c_str());
	}

	// resource manager
	Resources::Resources()
	{
		id = 0;
	}

	Resources::~Resources()
	{
		Free();
	}

	void Resources::Free()
	{
		Resource *r = 0;
		while(r = GetFirst())
		{
			Remove(r);
			delete r;
		}
	}

	Resource* Resources::AddResource(DOMString *name, DOMString* src, int type)
	{
		Resource *r = GetResource(name);
		if (r)
			return r;

		switch(type)
		{
		case RESOURCE_IMAGE:
			r = new ImageRes(name, src, ++id);
			break;
		default:
			r = new Resource(name, 0, type, ++id);
		}

		if (r)
			Push(r);
		return r;
	}

	Resource* Resources::GetResource(int id)
	{
		Resource *r = GetFirst();
		while(r)
		{
			if (r->GetId() == id)
				return r;
			r = r->next;
		}
		return 0;
	}

	Resource* Resources::GetResource(DOMString *name)
	{
		Resource *r = GetFirst();
		while(r)
		{
			if (*name == *r->GetName())
				return r;
			r = r->next;
		}
		return 0;
	}

	bool Resources::Load(Element *element)
	{
		// add fonts
		NodeList2 *n = element->GetElementsByTagName(&DOMString("font"));		
		for(int i=0; i<n->Length(); i++)
		{
			SafeNode snode((Element*)n->Item(i));
			DOMString *family = snode.GetValue("family")->Value();
			if (family)
			{
				AddResource(family, 0, RESOURCE_FONT);
			}
		}
		delete n;

		// add backgrounds
		n = element->GetElementsByTagName(&DOMString("background"));		
		for(int i=0; i<n->Length(); i++)
		{
			SafeNode snode((Element*)n->Item(i));
			DOMString *name = snode.GetValue("name")->Value();
			DOMString *src = snode.GetValue("src")->Value();
			if (src)
			{
				if (!name)
					name = src;
				AddResource(name, src, RESOURCE_IMAGE);
			}
		}
		delete n;

		// add images
		n = element->GetElementsByTagName(&DOMString("image"));		
		for(int i=0; i<n->Length(); i++)
		{
			SafeNode snode((Element*)n->Item(i));
			DOMString *name = snode.GetValue("name")->Value();
			DOMString *src = snode.GetValue("src")->Value();
			if (src)
			{
				if (!name)
					name = src;
				AddResource(name, src, RESOURCE_IMAGE);
			}
		}
		delete n;

		return true;
	}

	Resources* Resources::GetInstance()
	{
		static Resources *r = 0;
		if (!r)
			r = new Resources();
		return r;
	}

	void Resources::Dump()
	{
		Resource *r = GetFirst();
		while(r)
		{
			r->Dump();
			r = r->next;
		}
	}
}