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

#include <script/jsnodelist.h>

using namespace Dom;

JSBool JSNodeList::SetProperty(NodeList2* nodelist, JSInt16 id, JSContext *cx, JSObject *obj, jsval *vp)
{
	return JS_TRUE;
}

JSBool JSNodeList::GetProperty(NodeList2* nodelist, JSInt16 id, JSContext *cx, JSObject *obj, jsval *vp)
{
	return JS_TRUE;
}

JSBool JSNodeList::item(JSContext *cx, JSObject *obj, uintN argc, jsval *argv, jsval *rval)
{
	*rval = BOOLEAN_TO_JSVAL(JS_FALSE);

	if (argc != 1)
		return JS_TRUE;

	JSNodeList *p = (JSNodeList*) JS_GetPrivate(cx, obj);
	if (p->GetPrivate())
	{
		Element *e = (Element*)p->GetPrivate()->Item(JSVAL_TO_INT(argv[0]));
		if (e)
		{
			JSObject *obj = JSElement::Create(cx, e, false);
			*rval = OBJECT_TO_JSVAL(obj);
		}
	}
	return JS_TRUE;
}

JSBool JSNodeList::length(JSContext *cx, JSObject *obj, uintN argc, jsval *argv, jsval *rval)
{
	*rval = BOOLEAN_TO_JSVAL(JS_FALSE);

	if (argc != 0)
		return JS_TRUE;

	JSNodeList *p = (JSNodeList*) JS_GetPrivate(cx, obj);
	if (p->GetPrivate())
	{
		*rval = INT_TO_JSVAL(p->GetPrivate()->Length());
	}
	return JS_TRUE;
}

JSW_CLASS_NAME(JSNodeList, "NodeList")

JSW_BEGIN_PROPERTY_MAP(JSNodeList)
JSW_END_PROPERTY_MAP

JSW_BEGIN_METHOD_MAP(JSNodeList)
JSW_ADD_METHOD("item", item, 1)
JSW_ADD_METHOD("length", length, 0)
JSW_END_METHOD_MAP
