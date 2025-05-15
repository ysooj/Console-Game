#include <stdio.h>
#include <Windows.h>

void Mouse(int* x, int* y)
{
	// HANDLE : �ý��� ���ҽ��� ������ �� ���Ǵ� Windows�� Ư���� �����Դϴ�.
	HANDLE handleInput;
	HANDLE handleOutput;

	DWORD dword;

	// INPUT_RECORD : �ܼ� �Է� �̺�Ʈ�� ���� ������ �����ϴ� ����ü�Դϴ�.
	INPUT_RECORD inputRecord;

	// STD_INPUT_HANDLE : ǥ�� �Է¿� ���� �ڵ��� �˻��մϴ�.
	// STD_OUTPUT_HANDLE : ǥ�� ��¿� ���� �ڵ��� �˻��մϴ�.
	handleInput = GetStdHandle(STD_INPUT_HANDLE);
	handleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	// ENABLE_PROCESSED_INPUT : �ý����� Ctrl + C, Back Space�� ���� Ư�� �Է��� ó���� �� �ֽ��ϴ�.
	// ENABLE_MOUSE_INPUT : �ܼ� â���� �Է� �� ��ġ ���濡 ���� ������ ���콺 �̺�Ʈ�� ������ �� �ֽ��ϴ�.
	SetConsoleMode(handleInput, ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT);

	while (1)
	{
		ReadConsoleInput(handleInput, &inputRecord, 1, &dword);

		if (inputRecord.EventType == MOUSE_EVENT)
		{
			if (inputRecord.Event.MouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED)
			{
				*x = inputRecord.Event.MouseEvent.dwMousePosition.X;
				*y = inputRecord.Event.MouseEvent.dwMousePosition.Y;

				return;
			}
		}
	}
}

void Position(int x, int y)
{
	// X�� Y���� �����ϴ� ����ü�Դϴ�.
	COORD position = { x, y };

	// �ܼ� Ŀ���� ��ǥ�� �����ϴ� �Լ��Դϴ�.
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

int main()
{
	int x, y = 0;

	while (1)
	{
		Mouse(&x, &y);

		// �� �ڵ�� �ܼ� â�� �����ϰ� ������ش�.
		// �� �ڵ尡 ������ �ܼ� â���� ������ Ŭ���ߴ� ��ǥ�� ����� �����ְ� �ȴ�.
		system("cls");

		Position(x, y);

		// printf("%d, %d\n", x, y);
		printf("��\n");
	}

	return 0;
}