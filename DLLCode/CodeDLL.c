#include "HeaderDLL.h"

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
	switch (fdwReason)
	{
	case DLL_PROCESS_ATTACH:

		break;

	case DLL_THREAD_ATTACH:

		break;

	case DLL_THREAD_DETACH:

		break;

	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

double getSize(cord* cord)
{
	system("chcp 1251>nul");
	double d = sqrt((pow(cord->point2.X - cord->point1.X, 2) + pow(cord->point2.Y - cord->point1.Y, 2)), 2);
	return d;
}


