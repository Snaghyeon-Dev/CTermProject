#pragma once
#include"Library.h"
enum Bookcdt	//å�� ����
{
	Available,	//���� ����
	OnLoan,		//������
	Booked,		//�����
};
struct book 
{
	char bookName[15];	//å �̸�
	int id;				//å ��ȣ
	char authror[15];	//����
	char publisher[15];	//���ǻ�
	char position[15];	//å ��ġ
	enum Bookcdt bookCondition;	//å�� ����
}typedef Book;
void AddBook(struct Library* lib, struct Book book);		//å�� �߰��ϴ� �Լ�