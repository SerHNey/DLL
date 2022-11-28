#include "HeaderMain.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	HINSTANCE hMyDLL;
	if ((hMyDLL = LoadLibrary(PATH)) == NULL) return 1;
	getUser getuser = (getUser)GetProcAddress(hMyDLL, "getUser");
	searchUser searchuser = (searchUser)GetProcAddress(hMyDLL, "searchUser");
	User* user = calloc(1000, sizeof(User));
		getuser(user);
		searchuser(user, "Иванов");
	FreeLibrary(hMyDLL);
	return 0;
}
