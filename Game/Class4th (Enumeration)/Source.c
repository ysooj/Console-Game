#include <stdio.h>
#include <Windows.h>

enum State
{
	IDLE,
	ATTACK = 55,
	// 열거형의 경우 중간에 있는 값을 변경하게 되면, 변경된 값으로부터 1씩 증가합니다.
	// 원래는 0부터 1씩 증가한다. 원래 ATTACK 값은 1인데, 위와 같이 55로 바꾸면 DIE의 값이 56이 되는 것이다.
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
#pragma region 열거형
	// 여러 개의 상수 값을 하나의 이름으로 정의해서 사용하는 자료형입니다.

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