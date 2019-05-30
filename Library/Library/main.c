#include"UI.h"
void main()
{
	SetColor(1, 7);		//배경화면
	Library library;	//도서관 객체
	Initiate(&library);	//초기화한다.
	PrintMainMenuUI();	//메인메뉴를 출력한다.
}
