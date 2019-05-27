#pragma once
#include"Library.h"
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
void AddBook(struct Library* lib, struct Book book);		//책을 추가하는 함수