#pragma once
#include <windows.h>
#include <stdio.h>
#define PATH L"DLLCode.dll"
typedef double(_cdecl* getSize)(struct cord*);

typedef struct coordinats {
	COORD point1;
	COORD point2;
}cord;

