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

void getUser(User* user)
{
	system("chcp 1251>nul");
	FILE* pFile = fopen("Users.csv", "r");
	int size = 0;
	if (!pFile) perror("Error opening file");
	else
	{
		fseek(pFile, 0, SEEK_END);
		size = ftell(pFile);
		fclose(pFile);
	}

	HANDLE file = CreateFile(L"Users.csv", GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (file == INVALID_HANDLE_VALUE) //Проверка неоткрывается ли файл
	{
		MessageBox(NULL, L"Ошибка, нельзя открыть файл", L"Оповещение", MB_OK);
		return;
	}
	DWORD countFileSymbols;
	LPCSTR storoka = calloc(size, sizeof(char));
	if (!ReadFile(file, storoka, size, &countFileSymbols, NULL)) 
	{
		return 0;
	}
	CloseHandle(file);

	char* data = strtok(storoka, ";");
	int i = 0;
	while (data)
	{
		user[i].surname = data;
		data = strtok(NULL, ";\r\n");
		user[i].name = data;
		data = strtok(NULL, ";\r\n");
		user[i].middlename = data;
		data = strtok(NULL, ";\r\n");
		if (data != NULL)
		user[i].age = atoi(data);
		data = strtok(NULL, ";\r\n");
		i++;
	}
}


void searchUser(User* user, char* whoFind)
{
	User* userfind = malloc(sizeof(User));
	User* poiskSurName;
	int j = 0, countOfRows = 1;
	for (int i = 0; i < 100; i++)
	{
		if (strstr(user[i].surname, whoFind) != NULL)
		{
			userfind[j] = user[i];
			poiskSurName = realloc(userfind, (j + 2) * sizeof(User));
			j++;
			userfind = poiskSurName;
		}
	}
	writeUser(userfind, j);
}
void writeUser(User* user, int countCurrent)
{
	HANDLE Search = CreateFile(L"UsersSearch.csv", GENERIC_WRITE, FILE_SHARE_WRITE, NULL, CREATE_ALWAYS,FILE_ATTRIBUTE_NORMAL, NULL);
	DWORD countFileSymbols;
	float averageAge = 0;
	char* dataForWritting = calloc(100, sizeof(char));
	for (int i = 0; i < countCurrent; i++)
	{
		sprintf(dataForWritting, "%s;%s;%s;%d\n", user[i].surname, user[i].name, user[i].middlename, user[i].age);
		WriteFile(Search, dataForWritting, strlen(dataForWritting), &countFileSymbols, NULL);
		averageAge += user[i].age;
	}
	averageAge /= countCurrent;
	sprintf(dataForWritting, "Средний возраст: %f", averageAge);
	WriteFile(Search, dataForWritting, strlen(dataForWritting), &countFileSymbols, NULL);
	free(dataForWritting);
	CloseHandle(Search);
}
