//업다운 게임 만들기
//재귀 함수를 통해 구현해보기

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int CheckNumber(int _a)
{
	int input = -1;	//초기화
	//범위 외 숫자 입력시에는 다시 입력하게 반복
	//범위 내 숫자 입력하면 진행
	while (input > 99 || input < 0) {
		printf("0~99사이 숫자를 하나 입력해주세요: ");
		scanf(" %d", &input);
	}

	//입력한 숫자가 더 작으면 작다고 출력
	if (input < _a)
	{
		printf("%d는 숫자가 더 작습니다.\n", input);
		CheckNumber(_a);
	}

	//입력한 숫자가 더 크면 크다고 출력
	else if (input > _a)
	{
		printf("%d는 숫자가 더 큽니다.\n", input);
		CheckNumber(_a);
	}

	//입력한 숫자랑 같으면 해당 숫자를 반환
	else
	{
		return input;
	}
}

int main()
{
	srand((unsigned int)time(NULL));
	int input = 1;

	while (input) 
	{
		int num = rand() % 100;		//랜덤한 정답 설정
		num = CheckNumber(num);		//숫자 체크하는 재귀함수 실행

		printf("%d는 정답입니다.\n", num);		//정답 실행
		printf("0을 입력하면 종료, 다른 키를 입력하면 한번 더 진행합니다.\n ");		//0입력시 종료, 그 외는 실행

		scanf(" %d", &input);
	}

	return 0;
}