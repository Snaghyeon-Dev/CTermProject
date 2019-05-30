#include"book.h"
#include<string.h>
#include<stdio.h>
void InitBook(Book* bo)
{
	bo->id = -1;
}
void AddBook(Library* lib, const Book* book)
{
	printf("저장\n");
	lib->bo[book->id].id = book->id;										//문자열을 저장한 후 사용자에게 확인한다.
	strcpy_s(lib->bo[book->id].bookName, sizeof(char) * 15, book->bookName);
	strcpy_s(lib->bo[book->id].publisher, sizeof(char) * 15, book->publisher);
	strcpy_s(lib->bo[book->id].authror, sizeof(char) * 15, book->authror);
	system("cls");
	printf("일련번호 : %d\n", book->id);
	printf("책 이름 : %s\n", lib->bo[book->id].bookName);
	printf("저자 이름 : %s\n", lib->bo[book->id].authror);
	printf("출판사 이름 : %s\n", lib->bo[book->id].publisher);
	printf("완료되었습니다.\n아무 키나 눌러주세요.");
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
	while (listSize--)											//일정 폼을 갖춘 텍스트 파일에서 문자열을 읽어들여 저장한다.
	{
		fscanf_s(f, "%d\n", &intForInput);
		lib->bo[intForInput].id = intForInput;
		fscanf_s(f, "%s\n", charForInput, 15);
		strcpy_s( lib->bo[intForInput].bookName ,15,charForInput);
		fscanf_s(f, "%s\n", charForInput, 15);
		strcpy_s(lib->bo[intForInput].authror, 15, charForInput);
		fscanf_s(f, "%s\n", charForInput, 15);
		strcpy_s(lib->bo[intForInput].publisher, 15, charForInput);
		printf("일련번호 : %d\n", lib->bo[intForInput].id);
		printf("책 이름 : %s\n", lib->bo[intForInput].bookName);
		printf("저자 이름 : %s\n", lib->bo[intForInput].authror);
		printf("출판사 이름 : %s\n", lib->bo[intForInput].publisher);
	}
	fclose(f);
	printf("완료되었습니다.\n아무 키나 눌러주세요.");
	getchar(); getchar();
	return;
}
void SearchBookByString(const Library* lib, const char* string, int num)	//책을 ID기준으로 검색하여 결과를 출력합니다.
{
	printf("검사 문자열 : %s\n", string);
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
	printf("확인 - Enter");
	getchar(); getchar();
	return;
}
void PrintBook(const Book bo)
{
	printf("------------------------------------------------------\n");
	printf("일련번호 : %d\n", bo.id);
	printf("책 이름 : %s\n", bo.bookName);
	printf("출판사 이름 : %s\n", bo.publisher);
	printf("저자 이름 : %s\n", bo.authror);
	printf("------------------------------------------------------\n\n");
}