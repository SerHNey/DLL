#pragma once
#include <windows.h>
#include <stdio.h>
#define PATH L"DLLCode.dll"
typedef int(_cdecl* getUser)(struct MyStruct*);
typedef int(_cdecl* searchUser)(struct MyStruct*);

typedef struct User
{
	char* surname;
	char* name;
	char* middlename;
	int age;
}User;

