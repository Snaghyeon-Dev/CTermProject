#include"UI.h"
static int mainMenuCursor = 0;	//메뉴 커서의 위치 정보
static char** menu;				//메뉴 텍스트
static char** addBookMenu;		//addBookMenu텍스트
static char** SearchBookMenu;	//SearchBookMenu텍스트
static Library* mainLibrary;	//도서관 객체의 주소
//----------------------------------------------------------------초기화 및 템플릿-------------------------------------------------------------------------------------
void Initiate(const Library* library)		
{
	mainLibrary = library;
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

	SearchBookMenu = (char**)malloc(sizeof(char*) * 5);		//이차원 배열 초기화
	for (int i = 0; i < 5; i++)
		SearchBookMenu[i] = (char*)malloc(sizeof(char) * 15);
	SearchBookMenu[0] = "통합검색";
	SearchBookMenu[1] = "제목으로 찾기\n";
	SearchBookMenu[2] = "저자로 찾기\n";
	SearchBookMenu[3] = "출판사로 찾기\n";
	SearchBookMenu[4] = "일련번호로 찾기\n";
	
	addBookMenu = (char**)malloc(sizeof(char*) * 2);		//이차원 배열 초기화
	for (int i = 0; i < 2; i++)
		addBookMenu[i] = (char*)malloc(sizeof(char) * 15);
	addBookMenu[0] = "텍스트 파일로 추가하기\n";
	addBookMenu[1] = "직접 타이핑하여 추가하기\n";

	for (int i = 0; i < 1000; i++)
	{
		InitBook(&mainLibrary->bo[i]);
	}
}

int SelectTemplate(int Selector,int count,void (*fun)())
{
	switch (Selector)
	{
	case 72:			//↑키 입력
		printf("위키\n");
		SetmainMenuCursor(1,count);
		break;
	case 80:			//↓키 입력
		printf("아래키\n");
		SetmainMenuCursor(0,count);
		break;
	case 75:			//←키 입력
		break;
	case 77:			//→키 입력
		break;
	case 13:			//Enter키 입력
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
//----------------------------------------------------------------UI관련 기능-------------------------------------------------------------------------------------
void AddBookUI()			//책을 추가할 때 나오는 UI
{
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
void SearchBookUI()				//책을 검색할 때 나오는 UI
{
	int nSelect = 0;
	while (SelectTemplate(nSelect, 5, SearchBookSelectMenu))
	{
		gotoxy(0, 0);
		system("cls");
		ShowMenu(SearchBookMenu, 5);
		nSelect = _getch();
	}
	return;
}
void PrintAllBookUI()			 //책을 전체 출력할 때 나오는 ui
{
	system("cls");
	for (int i = 0; i < 1000; i++)
		if (mainLibrary->bo[i].id != -1)
			PrintBook(mainLibrary->bo[i]);
	printf("완료되었습니다.\n아무 키나 눌러주세요.");
	getchar(); getchar();
}
//----------------------------------------------------------------메뉴관련 기능-------------------------------------------------------------------------------------
void MainMenu()				//메인 메뉴입니다.
{
	switch (mainMenuCursor)
	{
	case 0:
		SearchBookUI();
	case 1:
		AddBookUI();
		break;
	case 3:
		PrintAllBookUI();
		break;
	}
}
void PrintMainMenuUI()			
{
	gotoxy(0, 0);				//커서이동입니다.
	int nSelect = 0;			//셀렉터입니다.(현재 선택된 메뉴 나타내기 위해)
	while (SelectTemplate(nSelect, 12, MainMenu))
	{
		gotoxy(0, 0);
		system("cls");
		ShowMenu(menu, 12);
		nSelect = _getch();

	}
	return;
}
void AddBookSelectMenu()		//AddBook 메뉴를 선택할 때 사용
{
	Book* bo=(Book*)malloc(sizeof(Book));
	char charForInput[15]="";
	int intForInput=0;
	system("cls");
	switch (mainMenuCursor)
	{
	case 0:
		printf("텍스트 파일을 실행파일에 위치시킨 후 아무 버튼이나 눌러주세요.\n");
		AddBookByFile(mainLibrary);
		break;
	case 1:
		printf("책의 제목을 입력해주세요.");
		scanf_s("%s", charForInput,sizeof(charForInput));
		strcpy_s(bo->bookName, sizeof(char) * 15,charForInput);
		printf("책의 저자를 입력해주세요.");
		scanf_s("%s", charForInput, sizeof(charForInput));
		strcpy_s(bo->authror, sizeof(charForInput), charForInput);
		printf("책의 출판사를 입력해주세요.");
		scanf_s("%s", charForInput, sizeof(charForInput));
		strcpy_s(bo->publisher, sizeof(charForInput), charForInput);
		printf("책의 일련번호를 입력해주세요.");
		scanf_s("%d", &intForInput);
		bo->id = intForInput;
		AddBook(mainLibrary, bo);
		break;
	}
	free(bo);
	return;
}
void SearchBookSelectMenu()	//SearchBook 메뉴를 선택할 때 사용
{
	char charForInput[15] = "";
	int intForInput = 0;
	system("cls");
	switch (mainMenuCursor)
	{
	case 0:
		printf("검색할 단어를 입력해주세요.\n");
		scanf_s("%s", charForInput, sizeof(charForInput));
		break;
	case 1:
		printf("책의 제목을 입력해주세요.\n");
		scanf_s("%s", charForInput, sizeof(charForInput));
		break;
	case 2:
		printf("책의 저자를 입력해주세요.\n");
		scanf_s("%s", charForInput, sizeof(charForInput));
		break;
	case 3:
		printf("책의 출판사를 입력해주세요.\n");
		scanf_s("%s", charForInput, sizeof(charForInput));
		break;
	case 4:
		printf("책의 일련번호를 입력해주세요.\n");
		scanf_s("%d", &intForInput);
		break;
	}
	/*
	if(mainMenuCursor==4)
		SearchBookByString(mainLibrary, itoa(intForInput, charForInput,15), mainMenuCursor);
	else*/
		SearchBookByString(mainLibrary, charForInput, mainMenuCursor);
		
	return;
}

void ShowMenu(char** menu, int count)			//메뉴 선택 화면을 출력하는 함수
{
	SetColor(1, 7);									//색을 바꾸고 메인메뉴를 출력해줍니다.
	printf("┌───────────────┐\n");
	for (int i = 0; i < 13; i++)
	{
		if (i == 6)
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
	printf("확인 = Enter 뒤로가기 = Backspace\n");
	ShowSelector(menu, mainMenuCursor, 20, 3, count);	//현재 메뉴에 따라 다양한 메뉴를 보여줍니다.
}

//----------------------------------------------------------------커서관련 기능-------------------------------------------------------------------------------------
void ShowSelector(char** menu,int cursor, int posX, int posY, int count)
{
	for (int i = 0; i < count; i++)	//선택된 값에 따라 폰트를 바꿔 출력해준다.
	{
		if (menu[i] == NULL)
			return;
		gotoxy(posX, 2 * i + posY);
		if (i == cursor)		//만약 선택된 메뉴라면
			SetColor(15, 1);
		printf("%s", menu[i]);
		SetColor(1, 7);
	}
}
void gotoxy(int x, int y)			//커서의 위치를 조정하는 함수
{
	COORD Pos = { x - 1, y - 1 };	//이것도 일종의 struct다
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);	//이 struct가 알려주는 위치로 커서이동
}
void Distructor()
{

}
void SetColor(unsigned short text, unsigned short back)	//글자의 배경, 색을 바꿔주는 함수
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text | (back << 4));
}
void SetmainMenuCursor(int i, int max)
{
	if (i == 0)						//메인 메뉴 커서의 값을 늘리거나 줄임
		mainMenuCursor++;
	else
		mainMenuCursor--;
	if (mainMenuCursor < 0)			//메뉴 커서가 가지는 최댓값과 최솟값을 설정함
		mainMenuCursor = 0;
	else if (mainMenuCursor >= max)
		mainMenuCursor = max - 1;
}