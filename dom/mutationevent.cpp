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

#include <dom/mutationevent.h>

namespace Dom
{

	void MutationEvent::InitMutationEvent(
		unsigned int eventTypeArg, 
		bool canBubbleArg, 
		bool cancellableArg, 
		DOMNode *relatedNodeArg, 
		DOMString prevValueArg, 
		DOMString newValueArg, 
		DOMString attrNameArg, 
		unsigned short attrChangeArg)
	{
		type = eventTypeArg;
		bubbles = canBubbleArg;
		cancellable = cancellableArg;
		relatedNode = relatedNodeArg;
		prevValue = prevValueArg;
		newValue = newValueArg;
		attrName = attrNameArg;
		attrChange = attrChangeArg;
	}

}