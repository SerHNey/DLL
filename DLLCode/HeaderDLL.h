#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct User
{
	char* surname;
	char* name;
	char* middlename;
	int age;
}User;

__declspec(dllimport) void getUser(User* user);
__declspec(dllimport) void searchUser(User* user, char* whoFind);
__declspec(dllimport) void writeUser(User* user, int countCurrent);

typedef int(_cdecl* forReadData)(User*);