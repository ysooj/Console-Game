#include <stdio.h>
#include <Windows.h>

enum State
{
	IDLE,
	ATTACK = 55,
	// �������� ��� �߰��� �ִ� ���� �����ϰ� �Ǹ�, ����� �����κ��� 1�� �����մϴ�.
	// ������ 0���� 1�� �����Ѵ�. ���� ATTACK ���� 1�ε�, ���� ���� 55�� �ٲٸ� DIE�� ���� 56�� �Ǵ� ���̴�.
	DIE
};

enum Color
{
	BLACK,
	DARKBLUE,
	DARKGREEN,
	DARKSKYBLUE,
	DARKRED,
	DARKVIOLET,
	DARKYELLOW,
	GRAY,
	DARKGRAY,
	BLUE,
	GREEN,
	SKYBLUE,
	RED,
	PURPLE,
	YELLOW,
	WHITE
};

int main()
{
#pragma region ������
	// ���� ���� ��� ���� �ϳ��� �̸����� �����ؼ� ����ϴ� �ڷ����Դϴ�.

	//	enum State state = ATTACK;
	//	
	//	switch (state)
	//	{
	//		case IDLE	: printf("IDLE");
	//			break;
	//	
	//		case ATTACK	: printf("ATTACK");
	//			break;
	//	
	//		case DIE	: printf("DIE");
	//			break;
	//	}
#pragma endregion

#pragma region Color

	for (int i = 0; i <= WHITE; i++)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
		printf("Attribute\n");
	}
#pragma endregion

	return 0;
}