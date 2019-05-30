#pragma once
enum Bookcdt	//책의 상태
{
	Available,	//대출 가능
	OnLoan,		//대출중
	Booked,		//예약됨
};
struct book 
{
	char bookName[15];	//책 이름
	int id;				//책 번호
	char authror[15];	//저자
	char publisher[15];	//출판사
	char position[15];	//책 위치
	enum Bookcdt bookCondition;	//책의 상태
}typedef Book;
struct library {
	int temp;
	Book bo[1000];
}typedef Library;
void PrintBook(const Book bo);	//책의 정보를 출력해줌
void InitBook(Book* bo);//책 초기화
void AddBook(Library* lib, Book* book);		//책을 추가하는 함수
void SearchBookByString(Library* lib, const char* string, int num);	//책을 검색하는 함수
