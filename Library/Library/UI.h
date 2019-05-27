#pragma once
#include<stdio.h>
#include<string.h>
#include<conio.h>
//_getc
#include<windows.h>
//커서 위치
#include<stdlib.h>
//콘솔 초기화

#include"Library.h"
void PrintMainMenu();		//메인 메뉴를 프린트하는 함수
void gotoxy(int x, int y);	//콘솔의커서 위치를 바꾸는 함수
void SetColor(unsigned short text, unsigned short back);			//글자색, 글자 배경색을 설정하는 함수
void ShowMenu(char** menu, int count);			//메뉴 선택 화면을 출력하는 함수
int SelectTemplate(int Selector, int count, void(*fun)(int num));			//메뉴를 선택할 때 
void Initiate(struct Library* library);			//초기화 함수
void SetmainMenuCursor(int i, int max);	//커서 위치를 조정하는 함수
void Distructor();			//프로그램 끝날 때 사용하는 함수
void AddBookUI();			//책을 추가할 때 나오는 UI
void ShowSelector(char** menu, int cursor, int posX, int posY, int count);	//표시 템플릿 출력
void MainMenu(int num);		//전체 메뉴를 선택할 때 사용
void AddBookSelectMenu(int num);//AddBook 메뉴를 선택할 때 사용
