#include "HeaderMain.h"

int main()
{
	HINSTANCE hMyDLL;
	if ((hMyDLL = LoadLibrary(PATH)) == NULL) return 1;
	getSize getSqize = (getSize)GetProcAddress(hMyDLL, "getSize");
	cord* cord = malloc(sizeof(cord));
	cord->point1.X = 2;
	cord->point1.Y = 1;
	cord->point2.X = 6;
	cord->point2.Y = 4;
	double result = getSqize(cord);
	FreeLibrary(hMyDLL);
	return 0;
}
