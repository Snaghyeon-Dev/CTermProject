#pragma once
#include<stdio.h>
#include<string.h>
#include<conio.h>
//_getc
#include<windows.h>
//Ŀ�� ��ġ
#include<stdlib.h>
//�ܼ� �ʱ�ȭ

#include"Library.h"
void PrintMainMenu();		//���� �޴��� ����Ʈ�ϴ� �Լ�
void gotoxy(int x, int y);	//�ܼ���Ŀ�� ��ġ�� �ٲٴ� �Լ�
void SetColor(unsigned short text, unsigned short back);			//���ڻ�, ���� ������ �����ϴ� �Լ�
void ShowMenu(char** menu, int count);			//�޴� ���� ȭ���� ����ϴ� �Լ�
int SelectTemplate(int Selector, int count, void(*fun)(int num));			//�޴��� ������ �� 
void Initiate(struct Library* library);			//�ʱ�ȭ �Լ�
void SetmainMenuCursor(int i, int max);	//Ŀ�� ��ġ�� �����ϴ� �Լ�
void Distructor();			//���α׷� ���� �� ����ϴ� �Լ�
void AddBookUI();			//å�� �߰��� �� ������ UI
void ShowSelector(char** menu, int cursor, int posX, int posY, int count);	//ǥ�� ���ø� ���
void MainMenu(int num);		//��ü �޴��� ������ �� ���
void AddBookSelectMenu(int num);//AddBook �޴��� ������ �� ���
