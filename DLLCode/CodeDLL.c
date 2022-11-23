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
	HANDLE file = CreateFile(L"Users.csv", GENERIC_READ, 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (file == INVALID_HANDLE_VALUE) //Проверка неоткрывается ли файл
	{
		MessageBox(NULL, L"Ошибка, нельзя открыть файл", L"Оповещение", MB_OK);
		return;
	}
	DWORD bytes;
	LPCSTR storoka = calloc(size, sizeof(char));
	if (!ReadFile(file, storoka, size, &bytes, NULL)) 
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
	User* userfind = calloc(1,sizeof(User));

	int countAllUsers = 0;
	int countFindUsers = 0;
	while (user[countAllUsers].surname)
	{
		if (strstr(user[countAllUsers].surname, whoFind) != NULL)
		{
			userfind[countFindUsers] = user[countAllUsers];
			userfind = realloc(userfind, (countFindUsers+ 2) * sizeof(User));
			countFindUsers++;
		}
		countAllUsers++;
	}
	writeUser(userfind, countFindUsers);
}
void writeUser(User* user, int countFindUser)
{
	HANDLE file = CreateFile(L"UsersSearch.csv", GENERIC_WRITE, FILE_SHARE_WRITE, NULL, CREATE_ALWAYS,FILE_ATTRIBUTE_NORMAL, NULL);
	DWORD bytes;
	float allage = 0;
	char* dataForWritting = calloc(100, sizeof(char));
	for (int i = 0; i < countFindUser; i++)
	{
		sprintf(dataForWritting, "%s;%s;%s;%d\n", user[i].surname, user[i].name, user[i].middlename, user[i].age);
		WriteFile(file, dataForWritting, strlen(dataForWritting), &bytes, NULL);
		allage += user[i].age;
	}
	allage /= countFindUser;
	sprintf(dataForWritting, "Средний возраст: %f", allage);
	WriteFile(file, dataForWritting, strlen(dataForWritting), &bytes, NULL);
	CloseHandle(file);
}
