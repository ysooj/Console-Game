#include <stdio.h>
#include <windows.h>
#include <conio.h>	// ����ȭ ����
#include <string.h>	// string ����

int screenIndex;	// ������ �ε��� ��ȣ
HANDLE screen[2];

#define UP 72
#define LEFT 75 
#define RIGHT 77
#define DOWN 80

void Initialize()	// �ʱ�ȭ �Լ�
{
	CONSOLE_CURSOR_INFO cursor;	// Ŀ���� ���� ����

	// ȭ�� ���۸� 2�� �����մϴ�.
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

void Flip()	// screen 2���� ��ü�����ִ� �Լ� ; �ø���
{
	SetConsoleActiveScreenBuffer(screen[screenIndex]);

	screenIndex = !screenIndex;	// 0�� ���� 1��, 1�� ���� 0���� �ٲ��ִ� ��.
}

void Clear()
{
	COORD position = { 0, 0 };

	DWORD dword;

	CONSOLE_SCREEN_BUFFER_INFO consoleBuffer;

	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

	GetConsoleScreenBufferInfo(handle, &consoleBuffer);

	int width = consoleBuffer.srWindow.Right - consoleBuffer.srWindow.Left + 1;		// ���۸� �簢�� ���·� ������ش�.
	int height = consoleBuffer.srWindow.Bottom - consoleBuffer.srWindow.Top + 1;	// ���۸� �簢�� ���·� ������ش�.

	FillConsoleOutputCharacter(screen[screenIndex], ' ', width * height, position, &dword);
}

void Render(int x, int y, const char* string)	// ���� ���۸� �� ���� �̰��� �̿��ؼ� ����������� �Ѵ�.
{
	DWORD dword;
	COORD position = { x, y };

	SetConsoleCursorPosition(screen[screenIndex], position);
	WriteFile(screen[screenIndex], string, strlen(string), &dword, NULL);	// string�� ���̸�ŭ string�� �������.
}

void Release()
{
	CloseHandle(screen[0]);
	CloseHandle(screen[1]);
}

int main()
{
	// ���� ������� Ű �Է��� �޾ƺ� ���̴�.
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

		Render(x, y, "��");
	}

	Release();
	return 0;
}