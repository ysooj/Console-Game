#include <stdio.h>
#include <windows.h>	// asinc 라는 함수를 사용하기 위해.

int main()
{
#pragma region GetAsyncKeyState
	// 포인터 배열 : const char * dialog[배열의 크기]
	const char* dialog[10];

	// 내 예시
	// dialog[0] = "안녕하세요. 제가 생각하는 과일이 무엇일까요?";
	// dialog[1] = "달콤한 과일을 좋아하시나요?";
	// dialog[2] = "네. 달콤하기도 하지만 새콤하기도 한 과일을 좋아합니다.";
	// dialog[3] = "크기가 주먹보다 큰가요?";
	// dialog[4] = "주먹보다 작습니다. 한 손에 들어오죠.";
	// dialog[5] = "씨가 하나인가요?";
	// dialog[6] = "씨가 매우 많습니다. 몇 개인지 세어볼까 생각한 적도 있습니다.";
	// dialog[7] = "혹시 딸기인가요?";
	// dialog[8] = "정답입니다! 똑똑하시네요.";
	// dialog[9] = "별말씀을.ㅎ";

	// 선생님 예시
	dialog[0] = "안녕하세요?";
	dialog[1] = "누구신가요?";
	dialog[2] = "탐정입니다.";
	dialog[3] = "저는 의뢰인입니다.";
	dialog[4] = "수상한 사건이 있다고 해서 왔습니다.";
	dialog[5] = "어떻게 알고 오셨나요?";
	dialog[6] = "이 사건에 대해 아시는 게 있나요?";
	dialog[7] = "조금 알고 있는데... ? 알려드릴까요?";
	dialog[8] = "말씀해주세요.";
	dialog[9] = ".......................";

	// 대화가 한번에 다 출력됨
	//	for (int i = 0; i < 10; i++)
	//	{
	//		// 짝수 : "탐정 : "
	//		if (i % 2 == 0)
	//		{
	//			printf("탐정 : %s\n", dialog[i]);
	//		}
	//	
	//		// 홀수 : "의뢰인 : "
	//		else
	//		{
	//			printf("의뢰인 : %s\n", dialog[i]);
	//		}
	//	}

	// 스페이스바를 누를 때마다 대화가 출력됨.
	int size = sizeof(dialog) / sizeof(dialog[0]);

	int i = 0;

	while (i < size)
	{
		// 0x0000 : 이전에 누른 적이 없고, 호출 시점에도 눌러지지 않은 상태
		// 0x0001 : 이전에 누른 적이 있고, 호출 시점에는 눌러지지 않은 상태
		// 0x8000 : 이전에 누른 적이 없고, 후출 시점에는 눌러져있는 상태
		// 0x8001 : 이전에 누른 적이 있고, 호출 시점에도 눌러져있는 상태

		if (GetAsyncKeyState(VK_SPACE) & 0x0001)
		{
			// 짝수 : "탐정 : "
			if (i % 2 == 0)
			{
				printf("탐정 : %s\n", dialog[i]);
			}

			// 홀수 : "의뢰인 : "
			else
			{
				printf("의뢰인 : %s\n", dialog[i]);
			}

			i++;
		}
	}
#pragma endregion

#pragma region 동기와 비동기
	// 동기 : A 와 B 작업이 있을 때, A 작업을 하고 있으면 다른 작업은 못 한다.
	//       예) scanf()

	// 비동기 : A 와 B 작업이 있을 때, A 작업을 하고 있어도 B 작업을 병행해서 할 수 있다.


#pragma endregion



	return 0;
}