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

#include <common.h>
#include <debug.h>
#include <js/src/jsapi.h>

namespace Script
{
	class ScriptEngine
	{
	public:
		ScriptEngine();
		~ScriptEngine();

		bool Initialize();
		void Shutdown();

		bool RegisterFunctions(JSFunctionSpec *funcs);
		bool RunScript(JSObject *obj, const char *script, long len);

		JSObject* DefineObject(const char* name, JSClass *jsClass, void *priv, bool permanent = true);

		JSRuntime* GetRuntime() { return jsRt; }
		JSObject*  GetGlobalObject() { return jsGlobal; }
		JSContext* GetContext() { return jsCx; }

	private:
		static JSClass jsGlobalClass;
		JSRuntime *jsRt;
		JSObject  *jsGlobal;
		JSContext *jsCx;

		TRACE
	};
}
