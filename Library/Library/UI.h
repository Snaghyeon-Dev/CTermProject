#pragma once
#include<stdio.h>
#include<string.h>
#include<conio.h>
//_getc
#include<windows.h>
//Ŀ�� ��ġ
#include<stdlib.h>
//�ܼ� �ʱ�ȭ
void PrintMainMenu();		//���� �޴��� ����Ʈ�ϴ� �Լ�
void gotoxy(int x, int y);	//�ܼ���Ŀ�� ��ġ�� �ٲٴ� �Լ�
void SetColor(unsigned short text, unsigned short back);			//���ڻ�, ���� ������ �����ϴ� �Լ�
void ShowMenu();			//�޴� ���� ȭ���� ����ϴ� �Լ�
void SelectMenu(int num);			//�޴��� ������ �� 
void Initiate();			//�ʱ�ȭ �Լ�
void SetmainMenuCorsor(int i);	//Ŀ�� ��ġ�� �����ϴ� �Լ�
void Distructor();			//���α׷� ���� �� ����ϴ� �Լ�
void AddBookUI();			//å�� �߰��� �� ������ UI