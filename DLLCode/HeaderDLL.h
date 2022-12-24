#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <stdio.h>
#include <math.h>

typedef struct coordinats {
	COORD point1;
	COORD point2;
}cord;
__declspec(dllimport) double getSize(cord* cord);


