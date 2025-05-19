#include <stdio.h>
#include <windows.h>
#include <conio.h>	// 동기화 관련
#include <string.h>	// string 관련

int screenIndex;	// 버퍼의 인덱스 번호
HANDLE screen[2];

#define UP 72
#define LEFT 75 
#define RIGHT 77
#define DOWN 80

void Initialize()	// 초기화 함수
{
	CONSOLE_CURSOR_INFO cursor;	// 커서에 대한 정보

	// 화면 버퍼를 2개 생성합니다.
	screen[0] = CreateConsoleScreenBuffer
	(
		GENERIC_READ | GENERIC_WRITE,
		0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL
	);

	screen[1] = CreateConsoleScreenBuffer
	(
		GENERIC_READ | GENERIC_WRITE,
		0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL
	);

	cursor.dwSize = 1;
	cursor.bVisible = FALSE; // FALSE = 0

	SetConsoleCursorInfo(screen[0], &cursor);
	SetConsoleCursorInfo(screen[1], &cursor);
}

void Flip()	// screen 2개를 교체시켜주는 함수 ; 플리핑
{
	SetConsoleActiveScreenBuffer(screen[screenIndex]);

	screenIndex = !screenIndex;	// 0일 때는 1로, 1일 때는 0으로 바꿔주는 것.
}

void Clear()
{
	COORD position = { 0, 0 };

	DWORD dword;

	CONSOLE_SCREEN_BUFFER_INFO consoleBuffer;

	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

	GetConsoleScreenBufferInfo(handle, &consoleBuffer);

	int width = consoleBuffer.srWindow.Right - consoleBuffer.srWindow.Left + 1;		// 버퍼를 사각형 형태로 만들어준다.
	int height = consoleBuffer.srWindow.Bottom - consoleBuffer.srWindow.Top + 1;	// 버퍼를 사각형 형태로 만들어준다.

	FillConsoleOutputCharacter(screen[screenIndex], ' ', width * height, position, &dword);
}

void Render(int x, int y, const char* string)	// 더블 버퍼를 쓸 때는 이것을 이용해서 렌더링해줘야 한다.
{
	DWORD dword;
	COORD position = { x, y };

	SetConsoleCursorPosition(screen[screenIndex], position);
	WriteFile(screen[screenIndex], string, strlen(string), &dword, NULL);	// string의 길이만큼 string을 출력해줌.
}

void Release()
{
	CloseHandle(screen[0]);
	CloseHandle(screen[1]);
}

int main()
{
	// 동기 방식으로 키 입력을 받아볼 것이다.
	char key = 0;
	
	int x = 0;
	int y = 0;

	Initialize();

	while (1)
	{
		Flip();

		Clear();

		key = _getch();

		if (key == -32)
		{
			key = _getch();
		}

		switch (key)
		{
		case 72:  if (y > 0) { y--; };
			break;

		case 75: if (x > 0) {x -= 2;};
			break;

		case 77: x += 2;
			break;

		case 80: y++;
			break;
		}

		//	if (x < 0)
		//	{
		//		x = 0;
		//	}
		//	
		//	else if (y < 0)
		//	{
		//		y = 0;
		//	}

		Render(x, y, "★");
	}

	Release();
	return 0;
}