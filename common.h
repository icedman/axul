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

#define UNICODE
#define _UNICODE

#define STRICT
#define WIN32_LEAN_AND_MEAN
#define XP_WIN
#define _CRT_SECURE_NO_DEPRECATE

#ifdef DLLEXPORT
#define ASHLAR_EXTERN  __declspec(dllexport)
#else
#define ASHLAR_EXTERN  __declspec(dllimport)
#endif

#include <stdio.h>

