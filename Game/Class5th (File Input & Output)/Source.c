#include <stdio.h>

#define SIZE 100000

void File(const char* image)
{
	FILE* file = fopen(image, "r");

	char buffer[SIZE] = { 0, };

	fread(buffer, 1, SIZE, file);

	printf("%s", buffer);

	fclose(file);
}

int main()
{
#pragma region ���� �����

#pragma region ���� ����

	// ù ��° �Ű� ���� (������ �̸�)
	// �� ��° �Ű� ���� (������ �Է� ���)

	// File Mode
	// r = �б�
	// r+ = �а� ���� (���ļ� ������)
	// w = ����		 (���� �ʱ�ȭ)
	// w+ = ���� �б� (���� �ʱ�ȭ)
	// a = append�� ����. �߰�
	// a+ = ���� �б�

	// FILE * : ������ ���� �ݴ� �� ���̴� ����ü ������
	//	FILE * file = fopen("Stat.txt", "w");
	//	// fopen() => ������ ���� �Լ�
	//	
	//	fputs("Health : 100 \n", file);
	//	fputs("Attack : 10 \n", file);
	//	fputs("Defense : 5 \n", file);
	//	
	//	fclose(file);
#pragma endregion

#pragma region ���� �б�

	//	FILE* file = fopen("Snoopy.txt", "r");
	//	FILE* file = fopen("WoodStock.txt", "r");
	//	
	//	// ���� �̸��� �߸� ���ų� �ϸ� FILE �����Ͱ� NULL���� �����ϰ� �Ǹ鼭 ���α׷��� �ٷ� ������ �ȴ�.
	//	
	//	char buffer[SIZE] = {0, };
	//	// ���ۿ��� char �ڷ������� �����Ͱ� ����ȴ�.
	//	// ���� 0���� �ʱ�ȭ�����ش�.
	//	
	//	// ù ��° �Ű����� : ���� �����͸� ������ �޸� ������ ������ ����
	//	// �� ��° �Ű����� : �� �������� �׸� ũ��
	//	// �� ��° �Ű����� : �����͸� �о�� ������ �׸��� ��
	//	// �� ��° �Ű����� : �����͸� �о�� ������ ������ ����
	//	
	//	fread(buffer, 1, SIZE, file);
	//	
	//	printf("%s", buffer);
	//	
	//	fclose(file);
	//	// ������ �����͸� ������ ��, ���Ϸ� �����͸� �����ϴ� �� ����.
	//	// ��, �ڵ� �󿡼� �����͸� �����ϰų� ���� ����, ���� �󿡼� �����͸� �����ϰų� �ϴ� �� ���ϴ�.

	// ���� �б⸦ �Լ��� ���� ������ �б�
	// File("Snoopy.txt");
	// File("WoodStock.txt");
	// File("Andy.txt");
#pragma endregion


#pragma endregion


	return 0;
}