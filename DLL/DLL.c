#include "HeaderMain.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	HINSTANCE hMyDLL;
	if ((hMyDLL = LoadLibrary(PATH)) == NULL) return 1;
	Simple simple = (Simple)GetProcAddress(hMyDLL, "simplenum");
	simple(0, 107);
	SimplehTread simplehTread = (SimplehTread)GetProcAddress(hMyDLL, "hTread");
	simplehTread(0, 500, 5);
	FreeLibrary(hMyDLL);
	return 0;
}
