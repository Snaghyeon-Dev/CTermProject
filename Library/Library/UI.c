#include"UI.h"
static int mainMenuCursor = 0;
static char** menu;
static char** addBookMenu;
static struct Library* mainLibrary;
void SetmainMenuCursor(int i,int max)
{
	if(i==0)
		mainMenuCursor++;
	else
		mainMenuCursor--;
	if(mainMenuCursor < 0)
		mainMenuCursor = 0;
	else if(mainMenuCursor>=max)
		mainMenuCursor = max-1;
}
void Initiate(struct Library* library)		
{
	mainLibrary = library;
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

	addBookMenu = (char**)malloc(sizeof(char*) * 2);		//������ �迭 �ʱ�ȭ
	for (int i = 0; i < 2; i++)
		addBookMenu[i] = (char*)malloc(sizeof(char) * 15);
	addBookMenu[0] = "�ؽ�Ʈ ���Ϸ� �߰��ϱ�\n";
	addBookMenu[1] = "���� Ÿ�����Ͽ� �߰��ϱ�\n";
}
void Distructor()
{
	
}
void SetColor(unsigned short text, unsigned short back)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text | (back << 4));
}
int SelectTemplate(int Selector,int count,void (*fun)())
{
	switch (Selector)
	{
	case 72:			//��Ű �Է�
		printf("��Ű\n");
		SetmainMenuCursor(1,count);
		break;
	case 80:			//��Ű �Է�
		printf("�Ʒ�Ű\n");
		SetmainMenuCursor(0,count);
		break;
	case 75:			//��Ű �Է�
		break;
	case 77:			//��Ű �Է�
		break;
	case 13:			//EnterŰ �Է�
		fun(mainMenuCursor);
		break;
	case 8:
		return 0;
		break;
	default:
		break;
	}
	return 1;
}
void PrintMainMenu()			//���� �޴��Դϴ�.
{
	gotoxy(0, 0);				//Ŀ���̵��Դϴ�.
	int nSelect = 0;			//�������Դϴ�.(���� ���õ� �޴� ��Ÿ���� ����)
	while (SelectTemplate(nSelect, 12, MainMenu)) 
	{
		gotoxy(0, 0);
		system("cls");
		ShowMenu(menu,12);
		nSelect = _getch();
		
	}
	return;
}
void AddBookUI()
{
	Book book;
	int nSelect = 0;
	while (SelectTemplate(nSelect, 2, AddBookSelectMenu)) 
	{
		gotoxy(0, 0);
		system("cls");
		ShowMenu(addBookMenu,2);
		nSelect = _getch();
		
	}
	return;
}
void MainMenu()
{
	switch (mainMenuCursor)
	{
	case 1:
		AddBookUI();
		break;
	}
}
void AddBookSelectMenu( )
{
	Book* bo=(Book*)malloc(sizeof(Book));
	char charForInput[15]="";
	int intForInput=0;
	system("cls");
	switch (mainMenuCursor)
	{
	case 0:
		printf("");
		break;
	case 1:
		printf("å�� ������ �Է����ּ���.");
		scanf_s("%s", charForInput,sizeof(charForInput));
		printf("\n %s\n",charForInput);
		strcpy_s(bo->authror, sizeof(char) * 15,charForInput);
		printf("å�� ���ڸ� �Է����ּ���.");
		scanf_s("%s", charForInput, sizeof(charForInput));
		strcpy_s(bo->authror, sizeof(charForInput), charForInput);
		printf("å�� ���ǻ縦 �Է����ּ���.");
		scanf_s("%s", charForInput, sizeof(charForInput));
		strcpy_s(bo->publisher, sizeof(charForInput), charForInput);
		printf("å�� �Ϸù�ȣ�� �Է����ּ���.");
		scanf_s("%d", &intForInput);
		bo->id = intForInput;
		break;
	}
	free(bo);
	system("cls");
	printf("�Ϸ�Ǿ����ϴ�.");
	getchar(); getchar();
	return;
}
void ShowMenu(char** menu, int count)
{
	SetColor(1, 7);									//���� �ٲٰ� ���θ޴��� ������ݴϴ�.
	printf("����������������������������������\n");
	for (int i = 0; i < 13; i++)
	{
		if (i == 6)
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
	printf("Ȯ�� = Enter �ڷΰ��� = Backspace\n");
	ShowSelector(menu, mainMenuCursor, 20, 3, count);	//���� �޴��� ���� �پ��� �޴��� �����ݴϴ�.
}
void ShowSelector(char** menu,int cursor, int posX, int posY, int count)
{
	for (int i = 0; i < count; i++)	//���õ� ���� ���� ��Ʈ�� �ٲ� ������ش�.
	{
		if (menu[i] == NULL)
			return;
		gotoxy(posX, 2 * i + posY);
		if (i == cursor)		//���� ���õ� �޴����
			SetColor(15, 1);
		printf("%s", menu[i]);
		SetColor(1, 7);
	}
}
void gotoxy(int x, int y)			//Ŀ���� ��ġ�� �����ϴ� �Լ�
{
	COORD Pos = { x - 1, y - 1 };	//�̰͵� ������ struct��
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);	//�� struct�� �˷��ִ� ��ġ�� Ŀ���̵�
}