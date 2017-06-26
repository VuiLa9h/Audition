#include<bits/stdc++.h>
#include<Windows.h>
#include<conio.h>
using namespace std;

HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
COORD charBufSize;
COORD characterPos;
SMALL_RECT writeArea;
CHAR_INFO Key[100], Introduce[3600], Audi;
int bm[3605], Kt[100], txt[36][100], Mang=5, dh[5]={88, 24, 26, 25, 27}, Combo;
int Cb[5]={67, 79, 77, 66, 79};
long long Score;
const char* Color[3]={"Black", "Blue", "Green"};
const char* Picture[9]= {"The Castle", "Two Mountain", "Super Mario", "Infinity Random", "Super Star", "ì Universe", "Hatsune Miku", "Vietnamese", "Gold Phoenix"};
const char* Bitmap[9]={"Castle.txt", "Mountain.txt", "SuperMario.txt", "Infinity.txt", "Star.txt", "Universe.txt", "Miku.txt", "Vietnam.txt", "Phoenix.txt"};
const char* Thumbnail[9]={"Castle.tbn", "Mountain.tbn", "SuperMario.tbn", "Infinity.tbn", "Star.tbn", "Universe.tbn", "Miku.tbn", "Vietnam.tbn", "Phoenix.tbn"};
typedef struct{
	string s;
	int score;
} Sc;

void resizeConsoleByPixel(int width, int height){	HWND console = GetConsoleWindow();	RECT r;	GetWindowRect(console, &r);	MoveWindow(console, r.left, r.top, width, height, TRUE); }
void resizeConsole(int width, int height){	SMALL_RECT windowSize = {0, 0, width, height};	SetConsoleWindowInfo(hConsoleOutput, true, &windowSize); }
void resizeScreenBuffer(int height){	COORD bufferSize = {100, height};	SetConsoleScreenBufferSize(hConsoleOutput, bufferSize); }
void gotoxy(int x, int y){	COORD Cursor_an_Pos = { x - 1, y - 1 };	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos); }
void ShowCursor(bool CursorVisibility){	CONSOLE_CURSOR_INFO cursor = {1, CursorVisibility};	SetConsoleCursorInfo(hConsoleOutput, &cursor); }

int GetKeyButton()
{
		char c=toupper(getch());
		if(c==-32)
		{
			c=getch();
			if(c==72) return 1;
			else if(c==77) return 2;
			else if(c==80) return 3;
			else if(c==75) return 4;
			else return 0;
		}
		if(c==13) return 5;
		else if(c==27) return -1;
		else if(c==87) return 6;
		else if(c==68) return 7;
		else if(c==83) return 8;
		else if(c==65) return 9;
		else return 0;
}

void nhapChu(const char* text)
{
	freopen(text,"r",stdin);
	for(int i=0;i<36;i++)	for(int j=0;j<=100;j++) scanf("%c", &txt[i][j]);
}

void nhapTranh(const char* img)
{
	freopen(img,"r",stdin);
	int n, h, bd=0;
	while((scanf("%d", &n))==1)
	{
		scanf("%X", &h);
		for(int i=0;i<n;i++)	bm[i+bd]=h;
		bd+=n;
	}
	system("cls");
}

void InChu(const char* text, const char* img, int timelimit)
{
	system("cls");
	nhapChu(text);
	nhapTranh(img);
    Introduce[3600];
    for(int i=0;i<36;i++)
    {
    	for(int j=0;j<100;j++)
    	{
    		Introduce[j+100*i].Char.AsciiChar = txt[i][j];
    		Introduce[j+100*i].Attributes=bm[j+100*i];
		}
	}
	COORD charBufSize = {100, 36};
	COORD characterPos = {0, 0};
	SMALL_RECT writeArea = {0, 0, 99, 35};
	WriteConsoleOutputA(hConsoleOutput, Introduce, charBufSize, characterPos, &writeArea);
	Sleep(timelimit);
}

void Intranh(const char* img, int timelimit)
{
	system("cls");
	nhapTranh(img);
   	Introduce[3600];
    for(int i=0;i<36;i++)
    {
    	for(int j=0;j<100;j++)
    	{
    		Introduce[j+100*i].Char.AsciiChar = 220;
    		Introduce[j+100*i].Attributes=bm[j+100*i];
		}
	}
	charBufSize = {100, 36};
	characterPos = {0, 0};
	writeArea = {0, 0, 99, 35};
	WriteConsoleOutputA(hConsoleOutput, Introduce, charBufSize, characterPos, &writeArea);
	Sleep(timelimit);
}

void Inchudacbiet(int xx, int yy, int _ConsoleColor, int _lenght)
{
	gotoxy(xx, yy);
	SetConsoleTextAttribute(hConsoleOutput, _ConsoleColor);
	for(int i=0;i<_lenght;i++) printf("%c", txt[yy-1][xx-1+i]);
}

void Inchutheoyeucau(int xx, int yy, int _ConsoleColor, int _lenght, char c)
{
	gotoxy(xx, yy);
	SetConsoleTextAttribute(hConsoleOutput, _ConsoleColor);
	for(int i=0;i<_lenght;i++) printf("%c", c);
}

void PlayGame()
{
	charBufSize = {100, 1};
	characterPos = {0, 0};
	writeArea = {0, 1, 99, 1};
	for(int i=0;i<100;i++){
		Kt[i]=rand()%4+1;
		Key[i].Char.AsciiChar = dh[Kt[i]];
	}
	WriteConsoleOutputA(hConsoleOutput, Key, charBufSize, characterPos, &writeArea);

	CHAR_INFO line3[100];
	for(int i=0;i<100;i++)
	{
		line3[i].Char.AsciiChar = ' ';
		line3[i].Attributes = bm[i+200]/16*16;
	}
	charBufSize = {100, 1};
	characterPos = {0, 0};
	writeArea = {0, 2, 99, 2};
	WriteConsoleOutputA(hConsoleOutput, line3, charBufSize, characterPos, &writeArea);
	charBufSize = {1, 1};
	characterPos = {0, 0};
	for(int i=0;i<100;i++)
	{
		int k = GetKeyButton();
		if(k==-1) return;
		Audi.Char.AsciiChar = dh[k];
		if(k==Kt[i])
		{
			Audi.Attributes = 10+bm[i+200]/16*16;
			Combo++;
			Score+=Combo;
			SetConsoleTextAttribute(hConsoleOutput, 10+bm[96]/16*16);
			gotoxy(91, 1);	printf("%10lld", Score);
		}
		else
		{
			Audi.Attributes = 12+bm[i+200]/16*16;
			gotoxy(Mang, 1); printf(" "); gotoxy(i+2, 3);
			Combo=0;
			Mang--;
			if(Mang==0) break;
		}
		gotoxy(51, 1);	printf("%5d", Combo);
		writeArea = {i, 2, i, 2};
		WriteConsoleOutputA(hConsoleOutput, &Audi, charBufSize, characterPos, &writeArea);
	}
	if(Mang==0) return;
	PlayGame();
}

void GhiDiem()
{
	system("cls");
	SetConsoleTextAttribute(hConsoleOutput, 44);
	for(int i=0;i<46;i++) printf(" ");
	printf("Audition");
	for(int i=0;i<46;i++) printf(" ");
	Sc scoreboard[100];
}

void Single()
{
	charBufSize = {5, 1};
	characterPos = {0, 0};
	writeArea = {0, 0, 4, 0};
	Mang=5, Score=0;
	CHAR_INFO Heart[5];
	for(int i=0;i<5;i++)
	{
		Heart[i].Char.AsciiChar = 3;
		Heart[i].Attributes = 16*(bm[i]/16)+12;
	}
	WriteConsoleOutputA(hConsoleOutput, Heart, charBufSize, characterPos, &writeArea);
	for(int i=0;i<5;i++)
	{
		Heart[i].Char.AsciiChar = Cb[i];
		Heart[i].Attributes = 16*(bm[i]/16)+10;
	}
	writeArea = {45, 0, 49, 0};
	WriteConsoleOutputA(hConsoleOutput, Heart, charBufSize, characterPos, &writeArea);
	for(int i=0;i<100;i++)	Key[i].Attributes = bm[i+100]/16*16+15;
	SetConsoleTextAttribute(hConsoleOutput, bm[0]/16*16+12);
	PlayGame();
	GhiDiem();
}

void PlayMulti()
{
	system("color 3B");
	system("cls");
	CHAR_INFO MangMau;
	MangMau.Char.AsciiChar = 3;
	charBufSize = {1,1};
	characterPos = {0, 0};
	for(int i=0;i<48;i++)
	{
		MangMau.Attributes = 16*(bm[i]/16+12)+12;
		writeArea = {i, 0, i, 0};
		WriteConsoleOutputA(hConsoleOutput, &MangMau, charBufSize, characterPos, &writeArea);
	}
	int k = GetKeyButton();
}

void ChooseColor()
{
	system("color E");
	system("cls");
	gotoxy(46, 1); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);
	gotoxy(46, 2); printf("%c List Color %c", 186, 186);
	gotoxy(46, 3); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188);
	for(int i=0;i<3;i++)
	{
		gotoxy(10, i*2+5);
		printf(Color[i]);
	}
	int k, _y=0;
	SetConsoleTextAttribute(hConsoleOutput, 10);
	gotoxy(7, _y*2+5); printf(">  ");
	gotoxy(10, _y*2+5);	printf(Color[_y]);
	while(true)
	{
		k = GetKeyButton();
		if(k==-1) return;
		else if(k==5) break;
		else if(k==1)
		{
			SetConsoleTextAttribute(hConsoleOutput, 14);
			gotoxy(7, _y*2+5); printf("   ");
			gotoxy(10, _y*2+5);	printf(Color[_y]);	
			_y=(_y+8)%9;
			SetConsoleTextAttribute(hConsoleOutput, 10);
			gotoxy(7, _y*2+5); printf(">  ");
			gotoxy(10, _y*2+5);	printf(Color[_y]);
		}
		else if(k==3)
		{
			SetConsoleTextAttribute(hConsoleOutput, 14);
			gotoxy(7, _y*2+5); printf("   ");
			gotoxy(10, _y*2+5);	printf(Color[_y]);
			_y=(_y+1)%9;
			SetConsoleTextAttribute(hConsoleOutput, 10);
			gotoxy(7, _y*2+5); printf(">  ");
			gotoxy(10, _y*2+5);	printf(Color[_y]);
		}
	}
	system("cls");
	Intranh(Bitmap[_y], 0);
}

void ChoosePicture()
{
	system("color E");
	system("cls");
	gotoxy(46, 1); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);
	gotoxy(46, 2); printf("%c List Theme %c", 186, 186);
	gotoxy(46, 3); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188);
	for(int i=0;i<9;i++)
	{
		gotoxy(10, i*2+5);
		printf(Picture[i]);
	}
	int k, _y=0;
	SetConsoleTextAttribute(hConsoleOutput, 10);
	gotoxy(7, _y*2+5); printf(">  ");
	gotoxy(10, _y*2+5);	printf(Picture[_y]);
	while(true)
	{
		k = GetKeyButton();
		if(k==-1) return;
		else if(k==5) break;
		else if(k==1)
		{
			SetConsoleTextAttribute(hConsoleOutput, 14);
			gotoxy(7, _y*2+5); printf("   ");
			gotoxy(10, _y*2+5);	printf(Picture[_y]);	
			_y=(_y+8)%9;
			SetConsoleTextAttribute(hConsoleOutput, 10);
			gotoxy(7, _y*2+5); printf(">  ");
			gotoxy(10, _y*2+5);	printf(Picture[_y]);
		}
		else if(k==3)
		{
			SetConsoleTextAttribute(hConsoleOutput, 14);
			gotoxy(7, _y*2+5); printf("   ");
			gotoxy(10, _y*2+5);	printf(Picture[_y]);
			_y=(_y+1)%9;
			SetConsoleTextAttribute(hConsoleOutput, 10);
			gotoxy(7, _y*2+5); printf(">  ");
			gotoxy(10, _y*2+5);	printf(Picture[_y]);
		}
	}
	system("cls");
	Intranh(Bitmap[_y], 0);
}

void Multi()
{
	system("color E");
	system("cls");
	gotoxy(46, 1); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);
	gotoxy(46, 2); printf("%c List  Game %c", 186, 186);
	gotoxy(46, 3); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188);
	gotoxy(39, 20); printf("   G a m e  M o d e  # 2");
	SetConsoleTextAttribute(hConsoleOutput, 10);
	gotoxy(39, 15); printf(">  G a m e  M o d e  # 1");
	int k, _y=0;
	while(true)
	{
		k = GetKeyButton();
		if(k==5) break;
		else if(k==-1) return;
		else if(k==1 || k==3)
		{
			SetConsoleTextAttribute(hConsoleOutput, 14);
			gotoxy(39, _y*5+15); printf("   G a m e  M o d e  # %d", _y+1);
			_y=1-_y;
			SetConsoleTextAttribute(hConsoleOutput, 10);
			gotoxy(39, _y*5+15); printf(">  G a m e  M o d e  # %d", _y+1);
		}
	}
	if(_y==1) ChooseColor();
	else ChoosePicture();
}

void StartGame()
{
	system("cls");
	SetConsoleTextAttribute(hConsoleOutput, 10);
	gotoxy(36, 20); printf("   M u l t i   P l a y e r s");
	SetConsoleTextAttribute(hConsoleOutput, 14);
	gotoxy(36, 15); printf(">  S i n g l e   P l a y e r");
	int kk, __y=0;
	while(1)
	{
		int kk = GetKeyButton();
		if(kk==1 || kk==3) __y=1-__y;
		else if(kk==5) break;
		else if(kk==-1) return;
		if(__y==1){
			SetConsoleTextAttribute(hConsoleOutput, 10);
			gotoxy(36, 15); printf("   S i n g l e   P l a y e r");
			SetConsoleTextAttribute(hConsoleOutput, 14);
			gotoxy(36, 20); printf(">  M u l t i   P l a y e r s");
		}
		else{
			SetConsoleTextAttribute(hConsoleOutput, 10);
			gotoxy(36, 20); printf("   M u l t i   P l a y e r s");
			SetConsoleTextAttribute(hConsoleOutput, 14);
			gotoxy(36, 15); printf(">  S i n g l e   P l a y e r");
		}

	}
	if(kk==-1) return;
	if(__y==0)
	{
		ChoosePicture();
		Single();
	}
	else Multi();
}

void AboutMe()
{
	SetConsoleTextAttribute(hConsoleOutput, 44);
	system("cls");
	printf("\n");
	for(int i=0;i<46;i++) printf(" ");
	printf("Audition");
	for(int i=0;i<46;i++) printf(" ");
	int k=0;
	while(true)
	{
		k = GetKeyButton();
		if(k==-1) break;
	}
}

void GoTo(int _yCursor)
{
	if(_yCursor==0) StartGame();
	else if(_yCursor==1) AboutMe();
	else exit(0);
}

void Loading()
{
	gotoxy(18, 24);
	for(int i=0;i<66;i++) printf("%c", 254);
	int rsc[8]={254, 252, 251, 250, 245, 250, 244, 253};
	char ld[9]="Loading!";
	gotoxy(47, 26);
	for(int i=0;i<8;i++)
	{
		SetConsoleTextAttribute(hConsoleOutput, rsc[i]);
		printf("%c", ld[i]);
	}
	gotoxy(18, 24);
	int rsccl[66]={254, 254, 254, 254, 254, 254, 254, 254, 254, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 250, 250, 250, 250, 245, 245, 245, 245, 245, 245, 245, 245, 245, 245, 250, 250, 250, 250, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 253, 253, 253, 253, 253, 253, 253, 253, 253};
	for(int i=0;i<66;i++)
	{
		SetConsoleTextAttribute(hConsoleOutput, rsccl[i]);
		printf("%c", 254);
		Sleep(50);
	}
}

void introduce()
{
	system("cls");
	Intranh("Bitmap.txt", 1500);
	system("cls"); system("color F0");
	InChu("Title.cxt", "Title.txt", 1500);
	Loading();
}

void HauKy()
{
	SetConsoleTitle(TEXT("Audition"));
	resizeConsoleByPixel(816, 615);
	resizeConsole(100, 36);
	resizeScreenBuffer(36);
	ShowCursor(false);
	system("color BB");
}

void MoDau()
{
	Intranh("Windows.txt", 5000);
	system("cls");	system("color F6");
	for(int i=0;i<43;i++) printf(" ");
	printf("Loading [000%%]\n");
	for(int i=1;i<=100;i++)
	{
		gotoxy(53, 1);	printf("%3d", i);
		gotoxy(i, 2);	printf("o");	Sleep(10);
	}
	introduce();
}

void BatDau()
{
	system("cls");
	InChu("Titlee.cxt","Titlee.txt",0);
	gotoxy(36, 15);	SetConsoleTextAttribute(hConsoleOutput, 12);	printf(">");
	int _yCursor = 0;
	while(true)
	{
		int k = GetKeyButton();
		if(k==1){
			Inchudacbiet(36, 15+2*_yCursor, 14, 23);
			_yCursor = (_yCursor + 2)%3;
			Inchutheoyeucau(36, 15+2*_yCursor, 12, 1, '>');
			Inchudacbiet(37, 15+2*_yCursor, 12, 23);
		}
		else if(k==3){
			Inchudacbiet(36, 15+2*_yCursor, 14, 23);
			_yCursor = (_yCursor + 1)%3;
			Inchutheoyeucau(36, 15+2*_yCursor, 12, 1, '>');
			Inchudacbiet(37, 15+2*_yCursor, 12, 23);
		}
		else if(k==5)	break;
	}
	GoTo( _yCursor);
	BatDau();
}

int main()
{
	HauKy();
	MoDau();
	BatDau();
}
