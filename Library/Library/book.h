#pragma once
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
struct library {
	int temp;
	Book bo[1000];
}typedef Library;
void PrintBook(const Book bo);	//å�� ������ �������
void InitBook(Book* bo);//å �ʱ�ȭ
void AddBook(Library* lib, Book* book);		//å�� �߰��ϴ� �Լ�
void SearchBookByString(Library* lib, const char* string, int num);	//å�� �˻��ϴ� �Լ�
