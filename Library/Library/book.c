#include"book.h"
#include<string.h>
void InitBook(Book* bo)
{
	bo->id == -1;
}

void AddBook(Library* lib, Book* book)
{
	printf("����\n");
	lib->bo[book->id].id = book->id;
	strcpy_s(lib->bo[book->id].bookName, sizeof(char) * 15, book->bookName);
	strcpy_s(lib->bo[book->id].publisher, sizeof(char) * 15, book->publisher);
	strcpy_s(lib->bo[book->id].authror, sizeof(char) * 15, book->authror);

	system("cls");
	printf("�Ϸù�ȣ : %d\n", book->id);
	printf("å �̸� : %s\n", lib->bo[book->id].bookName);
	printf("���ǻ� �̸� : %s\n", lib->bo[book->id].publisher);
	printf("���� �̸� : %s\n", lib->bo[book->id].authror);
	printf("�Ϸ�Ǿ����ϴ�.");
	getchar(); getchar();
}
void SearchBookByString(Library* lib, const char* string, int num)	//å�� ID�������� �˻��Ͽ� ����� ����մϴ�.
{
	printf("�˻� ���ڿ� : %s\n", string);
	int IsPrint = 0;

	
	
	for (int i = 0; i < 100; i++)
	{
		switch (num)
		{
		case 0:
			if (strstr(lib->bo[i].bookName, string) || strstr(lib->bo[i].publisher, string) || strstr(lib->bo[i].authror, string))
				IsPrint = 1;
			break;
		case 1:
			if (!strncmp(lib->bo[i].bookName, string, strlen(string)))
			{
				printf("�̸� : %s\n",lib->bo[i].bookName);
				IsPrint = 1;
			}
			break;
		case 2:
			if (strstr(lib->bo[i].publisher, string))
				IsPrint = 1;
			break;
		case 3:
			if (strstr(lib->bo[i].authror, string))
				IsPrint = 1;
			break;
		case 4:
			if (lib->bo[i].authror == atoi(string))
				IsPrint = 1;
			break;
		}
		if (IsPrint)
		{
			printf("i = %d\n",i);
			PrintBook(lib->bo[i]);
		}
		IsPrint = 0;

	}
	printf("Ȯ�� - Enter");
	getchar(); getchar();
}
void PrintBook(const Book bo)
{
	printf("------------------------------------------------------\n");
	printf("�Ϸù�ȣ : %d\n", bo.id);
	printf("å �̸� : %s\n", bo.bookName);
	printf("���ǻ� �̸� : %s\n", bo.publisher);
	printf("���� �̸� : %s\n", bo.authror);
	printf("------------------------------------------------------\n\n");
}