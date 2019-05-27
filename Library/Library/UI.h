#pragma once
#include<stdio.h>
#include<string.h>
#include<conio.h>
//_getc
#include<windows.h>
//커서 위치
#include<stdlib.h>
//콘솔 초기화
void PrintMainMenu();		//메인 메뉴를 프린트하는 함수
void gotoxy(int x, int y);	//콘솔의커서 위치를 바꾸는 함수
void SetColor(unsigned short text, unsigned short back);			//글자색, 글자 배경색을 설정하는 함수
void ShowMenu();			//메뉴 선택 화면을 출력하는 함수
void SelectMenu(int num);			//메뉴를 선택할 때 
void Initiate();			//초기화 함수
void SetmainMenuCorsor(int i);	//커서 위치를 조정하는 함수
void Distructor();			//프로그램 끝날 때 사용하는 함수
void AddBookUI();			//책을 추가할 때 나오는 UI