#include"book.h"
#include<string.h>
#include<stdio.h>
void InitBook(Book* bo)
{
	bo->id = -1;
}
void AddBook(Library* lib, const Book* book)
{
	printf("����\n");
	lib->bo[book->id].id = book->id;										//���ڿ��� ������ �� ����ڿ��� Ȯ���Ѵ�.
	strcpy_s(lib->bo[book->id].bookName, sizeof(char) * 15, book->bookName);
	strcpy_s(lib->bo[book->id].publisher, sizeof(char) * 15, book->publisher);
	strcpy_s(lib->bo[book->id].authror, sizeof(char) * 15, book->authror);
	system("cls");
	printf("�Ϸù�ȣ : %d\n", book->id);
	printf("å �̸� : %s\n", lib->bo[book->id].bookName);
	printf("���� �̸� : %s\n", lib->bo[book->id].authror);
	printf("���ǻ� �̸� : %s\n", lib->bo[book->id].publisher);
	printf("�Ϸ�Ǿ����ϴ�.\n�ƹ� Ű�� �����ּ���.");
	getchar(); getchar();
	return;
}
void AddBookByFile(Library* lib)
{
	FILE *f;
	char charForInput[15] = {""};
	int intForInput=0;
	int listSize = 0;
	fopen_s(&f,"BookList.txt","r");
	fscanf_s(f, "%d\n", &listSize);
	while (listSize--)											//���� ���� ���� �ؽ�Ʈ ���Ͽ��� ���ڿ��� �о�鿩 �����Ѵ�.
	{
		fscanf_s(f, "%d\n", &intForInput);
		lib->bo[intForInput].id = intForInput;
		fscanf_s(f, "%s\n", charForInput, 15);
		strcpy_s( lib->bo[intForInput].bookName ,15,charForInput);
		fscanf_s(f, "%s\n", charForInput, 15);
		strcpy_s(lib->bo[intForInput].authror, 15, charForInput);
		fscanf_s(f, "%s\n", charForInput, 15);
		strcpy_s(lib->bo[intForInput].publisher, 15, charForInput);
		printf("�Ϸù�ȣ : %d\n", lib->bo[intForInput].id);
		printf("å �̸� : %s\n", lib->bo[intForInput].bookName);
		printf("���� �̸� : %s\n", lib->bo[intForInput].authror);
		printf("���ǻ� �̸� : %s\n", lib->bo[intForInput].publisher);
	}
	fclose(f);
	printf("�Ϸ�Ǿ����ϴ�.\n�ƹ� Ű�� �����ּ���.");
	getchar(); getchar();
	return;
}
void SearchBookByString(const Library* lib, const char* string, int num)	//å�� ID�������� �˻��Ͽ� ����� ����մϴ�.
{
	printf("�˻� ���ڿ� : %s\n", string);
	int IsPrint = 0;
	int ad = 0;
	
	
	for (int i = 0; i < 1000; i++)
	{
		switch (num)
		{
		case 0:
			if (strstr(lib->bo[i].bookName, string) || strstr(lib->bo[i].publisher, string) || strstr(lib->bo[i].authror, string))
				IsPrint = 1;
			break;
		case 1:
			if (strstr(lib->bo[i].bookName, string))
				IsPrint = 1;
			break;
		case 2:
			if (strstr(lib->bo[i].authror, string))
				IsPrint = 1;
			break;
		case 3:
			if (strstr(lib->bo[i].publisher, string))
				IsPrint = 1;
			break;
		case 4:
			if (lib->bo[i].authror == atoi(string))
				IsPrint = 1;
			break;
		}
		if (IsPrint&&lib->bo[i].id != -1)
				PrintBook(lib->bo[i]);
		IsPrint = 0;
	}
	printf("Ȯ�� - Enter");
	getchar(); getchar();
	return;
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