#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Shuffle(int array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		int seed = rand() % size;

		int temporary = array[seed];
		
		array[seed] = array[i];

		array[i] = temporary;
	}
}

int main()
{
#pragma region 의사 난수
	// rand() : 0 ~ 32767 사이의 난수의 값을 반환하는 함수입니다.

	// time(NULL) : 1970년 1월 1일 00:00:00 UTC 이후에 지난 초(second)를 반환하는 함수입니다.

	// srand(seed) : 난수 생성기의 시드를 설정하는 함수입니다.

	// srand(time(NULL));
	// 
	// int indedx = rand() % 10 + 1;
	// 
	// printf("index의 값 : %d\n", indedx);
#pragma endregion

#pragma region 셔플 함수
	// int list[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	// 
	// int size = sizeof(list) / sizeof(int);
	// 
	// Shuffle(list, size);
	// for (int i = 0; i < size; i++)
	// {
	// 	printf("%d\n", list[i]);
	// }
#pragma endregion

#pragma region 게임

	srand(time(NULL));

	int seed = rand() % 50 + 1;

	int heart = 5;

	int number;

	while (heart > 0)
	{
		// 하트
		if (heart == 5)
		{
			printf("HP : ♥♥♥♥♥\n");
		}
		else if (heart == 4)
		{
			printf("HP : ♥♥♥♥♡\n");
		}
		else if (heart == 3)
		{
			printf("HP : ♥♥♥♡♡\n");
		}
		else if (heart == 2)
		{
			printf("HP : ♥♥♡♡♡\n");
		}
		else if (heart == 1)
		{
			printf("HP : ♥♡♡♡♡\n");
		}

		// 입력
		printf("1 ~ 50 중 정답이라고 생각하는 숫자를 입력하세요. : ");
		scanf_s("%d", &number);
		// 힌트
		if (seed > number)
		{
			printf("컴퓨터가 가지고 있는 값보다 작습니다.\n");
			printf("--------------------------------------------------------\n");
		}

		else if (seed < number)
		{
			printf("컴퓨터가 가지고 있는 값보다 큽니다.\n");
			printf("--------------------------------------------------------\n");
		}

		else
		{
			printf("-----------------------\n");
			printf("-----------------------\n");
			printf("        VICTORY\n");
			printf("-----------------------\n");
			printf("-----------------------\n");
			break;
		}

		heart -= 1;

		if (heart == 0)
		{
			printf("-----------------------\n");
			printf("-----------------------\n");
			printf("        DEFEAT\n");
			printf("        정답 : %d\n", seed);
			printf("-----------------------\n");
			printf("-----------------------\n");
		}
	}
#pragma endregion

	return 0;
}