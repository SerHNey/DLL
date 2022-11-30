#pragma once
#include <windows.h>
#include <stdio.h>
#define PATH L"DLLCode.dll"
typedef int(_cdecl* Simple)(int a, int b);
typedef int(_cdecl* SimplehTread)(int a, int b, int countHtread);


