#include "HeaderDLL.h"
CRITICAL_SECTION crit;
PCRITICAL_SECTION pcrit = &crit;

int v = 0;

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


int isPrime(int n)
{
	if (n == 1 || n == 0)
		return 0;
	for (int i = 2; i <= (n / 2); i++)
		if ((n % i) == 0) return 0;
	return 1;
}

int simplenum(int a, int b)
{
	int count = 0;
	for (size_t i = a; i <= b; i++)
	{
		if (isPrime(i))
			count++;	
	}
	return count;
}

void simplenum2(int param[])
{
	int a = param[0];
	int b = param[1];
	int count = 0;
	for (size_t i = a; i <= b; i++)
	{
		if (isPrime(i))

			v++;		
	}
	count = v;
	ExitThread(v);
}


int hTread(int a, int b, int countHtread) {
	int param[2];
	param[0] = a;
	param[1] = b;
	int range = b - a;
	int d = range / countHtread;
	int count = 0;
	HANDLE hTread[100];
	InitializeCriticalSection(pcrit);
	for (size_t i = 0; i < countHtread; i++)
	{
		hTread[i] = CreateThread(NULL, 0, simplenum2, param, 0, count);
	}	
	DeleteCriticalSection(pcrit);
	WaitForMultipleObjects(countHtread, hTread, TRUE, INFINITE);


}