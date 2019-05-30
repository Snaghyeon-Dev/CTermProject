#include"book.h"
#include<string.h>
void InitBook(Book* bo)
{
	bo->id == -1;
}

void AddBook(Library* lib, Book* book)
{
	printf("저장\n");
	lib->bo[book->id].id = book->id;
	strcpy_s(lib->bo[book->id].bookName, sizeof(char) * 15, book->bookName);
	strcpy_s(lib->bo[book->id].publisher, sizeof(char) * 15, book->publisher);
	strcpy_s(lib->bo[book->id].authror, sizeof(char) * 15, book->authror);

	system("cls");
	printf("일련번호 : %d\n", book->id);
	printf("책 이름 : %s\n", lib->bo[book->id].bookName);
	printf("출판사 이름 : %s\n", lib->bo[book->id].publisher);
	printf("저자 이름 : %s\n", lib->bo[book->id].authror);
	printf("완료되었습니다.");
	getchar(); getchar();
}
void SearchBookByString(Library* lib, const char* string, int num)	//책을 ID기준으로 검색하여 결과를 출력합니다.
{
	printf("검사 문자열 : %s\n", string);
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
				printf("이름 : %s\n",lib->bo[i].bookName);
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
	printf("확인 - Enter");
	getchar(); getchar();
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