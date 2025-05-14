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
#pragma region �ǻ� ����
	// rand() : 0 ~ 32767 ������ ������ ���� ��ȯ�ϴ� �Լ��Դϴ�.

	// time(NULL) : 1970�� 1�� 1�� 00:00:00 UTC ���Ŀ� ���� ��(second)�� ��ȯ�ϴ� �Լ��Դϴ�.

	// srand(seed) : ���� �������� �õ带 �����ϴ� �Լ��Դϴ�.

	// srand(time(NULL));
	// 
	// int indedx = rand() % 10 + 1;
	// 
	// printf("index�� �� : %d\n", indedx);
#pragma endregion

#pragma region ���� �Լ�
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

#pragma region ����

	srand(time(NULL));

	int seed = rand() % 50 + 1;

	int heart = 5;

	int number;

	while (heart > 0)
	{
		// ��Ʈ
		if (heart == 5)
		{
			printf("HP : ����������\n");
		}
		else if (heart == 4)
		{
			printf("HP : ����������\n");
		}
		else if (heart == 3)
		{
			printf("HP : ����������\n");
		}
		else if (heart == 2)
		{
			printf("HP : ����������\n");
		}
		else if (heart == 1)
		{
			printf("HP : ����������\n");
		}

		// �Է�
		printf("1 ~ 50 �� �����̶�� �����ϴ� ���ڸ� �Է��ϼ���. : ");
		scanf_s("%d", &number);
		// ��Ʈ
		if (seed > number)
		{
			printf("��ǻ�Ͱ� ������ �ִ� ������ �۽��ϴ�.\n");
			printf("--------------------------------------------------------\n");
		}

		else if (seed < number)
		{
			printf("��ǻ�Ͱ� ������ �ִ� ������ Ů�ϴ�.\n");
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
			printf("        ���� : %d\n", seed);
			printf("-----------------------\n");
			printf("-----------------------\n");
		}
	}
#pragma endregion

	return 0;
}