#pragma once
#include"book.h"
enum Usercdt	//사용자의 상태
{
	Normal,		//일반
	Limited,	//제한됨
};
struct user 
{
	char userName[10];	//사용자 이름
	int bookCount;		//빌린 책 수
	struct Book* myBook[10];	//빌린 책 목록
	enum Usercdt userCondition;	//사용자의 상태
}typedef User;