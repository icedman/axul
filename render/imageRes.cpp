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

#include <render/imageRes.h>

namespace Render
{
	ImageRes::ImageRes(DOMString* n, DOMString *src, int i)
	{
		id = i;
		type = RESOURCE_IMAGE;
		if (n)
		{
			name = *n;
		} else {
			name = *src;
		}

		// todo: load jpg, bitmap, && gif
		try {
			img = Cairo::ImageSurface::create_from_png(*src);
		} catch (Cairo::logic_error) {
			printf("error loading png\n");
		}
	}
}