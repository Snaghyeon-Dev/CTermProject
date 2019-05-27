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
	menu = (char**)malloc(sizeof(char*)*12);		//이차원 배열 초기화
	for (int i = 0; i < 12; i++)
		menu[i] = (char*)malloc(sizeof(char) * 10);
	menu[0] = "도서 검색\n";						//후 데이터 저장
	menu[1] = "도서 추가\n";
	menu[2] = "도서 삭제\n";
	menu[3] = "도서 전체 목록\n";
	menu[4] = "도서 대출\n";
	menu[5] = "도서 반납\n";
	menu[6] = "도서 대출 연장\n";
	menu[7] = "회원 추가\n";
	menu[8] = "회원 삭제\n";
	menu[9] = "회원 검색\n";
	menu[10] = "회원 전체 목록\n";
	menu[11] = "회원 제제\n";

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
		case 72:			//↑키 입력
			printf("위키\n");
			SetmainMenuCorsor(1);
			break;
		case 80:			//↓키 입력
			printf("아래키\n");
			SetmainMenuCorsor(0);
			break;
		case 75:			//←키 입력
			break;
		case 77:			//→키 입력
			break;
		case 13:			//Enter키 입력
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
	printf("┌───────────────┐\n");

	for (int i = 0; i < 15; i++)
	{
		if (i == 8)
			printf("│   도서 관리   │\n");
		printf("│\t\t│\n");
	}

	printf("├───────────────┤\n");

	for (int i = 0; i < 10; i++)
	{
		if (i == 5)
			printf("│   회원 관리   │\n");
		printf("│\t\t│\n");
	}

	printf("└───────────────┘\n");


	for (int i = 0; i < 12; i++)	//선택된 값에 따라 폰트를 바꿔 출력해준다.
	{
		if(i<7)
			gotoxy(20,2*i+3);
		else
			gotoxy(20, 2 * i + 5);


		if (i == mainMenuCorsor)		//만약 선택된 메뉴라면
			SetColor(15, 1);
		printf("%s", menu[i] );
		SetColor(1,7);
	}
	
	
}
void gotoxy(int x, int y)			//커서의 위치를 조정하는 함수
{
	COORD Pos = { x - 1, y - 1 };	//이것도 일종의 struct다
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);	//이 struct가 알려주는 위치로 커서이동
}