#include"UI.h"
static int mainMenuCorsor = 0;
static char** menu;
void SetmainMenuCorsor(int i)
{
	if(i==0)
		mainMenuCorsor++;
	else
		mainMenuCorsor--;
	if(mainMenuCorsor < 0)
		mainMenuCorsor = 0;
}
void Initiate()		
{
	menu = (char**)malloc(sizeof(char*)*12);		//������ �迭 �ʱ�ȭ
	for (int i = 0; i < 12; i++)
		menu[i] = (char*)malloc(sizeof(char) * 10);
	menu[0] = "���� �˻�\n";						//�� ������ ����
	menu[1] = "���� �߰�\n";
	menu[2] = "���� ����\n";
	menu[3] = "���� ��ü ���\n";
	menu[4] = "���� ����\n";
	menu[5] = "���� �ݳ�\n";
	menu[6] = "���� ���� ����\n";
	menu[7] = "ȸ�� �߰�\n";
	menu[8] = "ȸ�� ����\n";
	menu[9] = "ȸ�� �˻�\n";
	menu[10] = "ȸ�� ��ü ���\n";
	menu[11] = "ȸ�� ����\n";

}
void Distructor()
{
	
}
void SetColor(unsigned short text, unsigned short back)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text | (back << 4));
}
void PrintMainMenu()
{
	gotoxy(0, 0);
	int nSelect = 0;
	while (1) {
		
		gotoxy(0, 0);
		system("cls");
	
		ShowMenu();
		nSelect = _getch();
		switch (nSelect)
		{
		case 72:			//��Ű �Է�
			printf("��Ű\n");
			SetmainMenuCorsor(1);
			break;
		case 80:			//��Ű �Է�
			printf("�Ʒ�Ű\n");
			SetmainMenuCorsor(0);
			break;
		case 75:			//��Ű �Է�
			break;
		case 77:			//��Ű �Է�
			break;
		case 13:			//EnterŰ �Է�
			SelectMenu(mainMenuCorsor);
			break;
		default:
			break;
		}
	}
	return;
}
void SelectMenu(int num)
{
	switch (num)
	{
		case 
	}
}
void ShowMenu()
{
	SetColor(1, 7);
	printf("����������������������������������\n");

	for (int i = 0; i < 15; i++)
	{
		if (i == 8)
			printf("��   ���� ����   ��\n");
		printf("��\t\t��\n");
	}

	printf("����������������������������������\n");

	for (int i = 0; i < 10; i++)
	{
		if (i == 5)
			printf("��   ȸ�� ����   ��\n");
		printf("��\t\t��\n");
	}

	printf("����������������������������������\n");


	for (int i = 0; i < 12; i++)	//���õ� ���� ���� ��Ʈ�� �ٲ� ������ش�.
	{
		if(i<7)
			gotoxy(20,2*i+3);
		else
			gotoxy(20, 2 * i + 5);


		if (i == mainMenuCorsor)		//���� ���õ� �޴����
			SetColor(15, 1);
		printf("%s", menu[i] );
		SetColor(1,7);
	}
	
	
}
void gotoxy(int x, int y)			//Ŀ���� ��ġ�� �����ϴ� �Լ�
{
	COORD Pos = { x - 1, y - 1 };	//�̰͵� ������ struct��
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);	//�� struct�� �˷��ִ� ��ġ�� Ŀ���̵�
}