#pragma once
#include"book.h"
enum Usercdt	//������� ����
{
	Normal,		//�Ϲ�
	Limited,	//���ѵ�
};
struct user 
{
	char userName[10];	//����� �̸�
	int bookCount;		//���� å ��
	struct Book* myBook[10];	//���� å ���
	enum Usercdt userCondition;	//������� ����
}typedef User;