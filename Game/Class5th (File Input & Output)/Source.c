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
#pragma region 파일 입출력

#pragma region 파일 쓰기

	// 첫 번째 매개 변수 (파일의 이름)
	// 두 번째 매개 변수 (파일의 입력 모드)

	// File Mode
	// r = 읽기
	// r+ = 읽고 쓰기 (겹쳐서 써진다)
	// w = 쓰기		 (파일 초기화)
	// w+ = 쓰고 읽기 (파일 초기화)
	// a = append의 약자. 추가
	// a+ = 쓰고 읽기

	// FILE * : 파일을 열고 닫는 데 쓰이는 구조체 포인터
	//	FILE * file = fopen("Stat.txt", "w");
	//	// fopen() => 파일을 여는 함수
	//	
	//	fputs("Health : 100 \n", file);
	//	fputs("Attack : 10 \n", file);
	//	fputs("Defense : 5 \n", file);
	//	
	//	fclose(file);
#pragma endregion

#pragma region 파일 읽기

	//	FILE* file = fopen("Snoopy.txt", "r");
	//	FILE* file = fopen("WoodStock.txt", "r");
	//	
	//	// 파일 이름을 잘못 적거나 하면 FILE 포인터가 NULL값을 참조하게 되면서 프로그램이 바로 터지게 된다.
	//	
	//	char buffer[SIZE] = {0, };
	//	// 버퍼에는 char 자료형으로 데이터가 저장된다.
	//	// 먼저 0으로 초기화시켜준다.
	//	
	//	// 첫 번째 매개변수 : 읽은 데이터를 저장할 메모리 버퍼의 포인터 변수
	//	// 두 번째 매개변수 : 각 데이터의 항목 크기
	//	// 세 번째 매개변수 : 데이터를 읽어올 데이터 항목의 수
	//	// 네 번째 매개변수 : 데이터를 읽어올 파일의 포인터 변수
	//	
	//	fread(buffer, 1, SIZE, file);
	//	
	//	printf("%s", buffer);
	//	
	//	fclose(file);
	//	// 실제로 데이터를 관리할 때, 파일로 데이터를 관리하는 게 좋다.
	//	// 즉, 코드 상에서 데이터를 수정하거나 하지 말고, 파일 상에서 데이터를 수정하거나 하는 게 편하다.

	// 파일 읽기를 함수로 만들어서 파일을 읽기
	// File("Snoopy.txt");
	// File("WoodStock.txt");
	// File("Andy.txt");
#pragma endregion


#pragma endregion


	return 0;
}