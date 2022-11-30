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

int simplenum2(int param[])
{
	int a = param[0];
	int b = param[1];
	int count = 0;
	for (size_t i = a; i <= b; i++)
	{
		if (isPrime(i))
			count++;
	}
	return count;
}


int hTread(int a, int b, int countHtread) {
	int param[2];
	param[0] = a;
	param[1] = b;
	int count = 0;
	HANDLE hTread = calloc(countHtread + 1, sizeof(HANDLE));

	HANDLE hTread1 = CreateThread(NULL, 0, simplenum2, param, 0, count);

	WaitForSingleObject(hTread1, INFINITE);
	//for (size_t i = 0; i < countHtread; i++)
	//{
	//	hTread = CreateThread(NULL, 0, simplenum2, param, 0, count);
	//}	

	//WaitForMultipleObjects(countHtread, hTread, TRUE, INFINITE);

}