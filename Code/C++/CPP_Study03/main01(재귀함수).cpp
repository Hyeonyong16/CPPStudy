//지뢰찾기 만들기
//1. 일단 10, 10 사이즈
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//board에서 입력받은 x, y좌표를 확인하는 함수
bool Dig(int _x, int _y, char _board[][10], char _screen[][10])
{
	//좌표를 1~10으로 입력 받기에 1씩 빼줌
	int X = _x - 1;
	int Y = _y - 1;

	bool val = true;	//스크린에 반환할 값


	if (_board[Y][X] == '*') return false;	//지뢰를 누르면 false 반환
	if (X < 0 || X > 9) return false;
	if (Y < 0 || Y > 9) return false;

	if (_screen[Y][X] != '+') return true;	//이미 확인한 칸이면 0반환
	
	if (val) _screen[Y][X] = _board[Y][X];

	for (int h = -1; h < 2; h++)
	{
		for (int w = -1; w < 2; w++)
		{
			if(_screen[Y][X] == '0') val = Dig(_x-w, _y-h, _board, _screen);
		}
	}

	return true;
}

int main()
{
	char board[10][10] = { 0 };	//10 * 10 크기 보드 생성 및 초기화
	char screen[10][10] = { 0 };	//화면에 출력할 스크린
	int numBombs = 0;			//지뢰의 개수
	int numBombsOnBoard = 0;	//현재 보드에 생성된 지뢰 개수

	int isAlive = 1;
	
	srand((unsigned int)time(NULL));

	//보드 생성
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			int randNum = rand() % 8;
			if (randNum == 1) board[i][j] = '*';		//20으로 나눈 나머지 값이 1이면 지뢰ㅇㅇ
			else board[i][j] = '0';
		}
	}

	//지뢰에 맞춰서 보드 숫자 갱신
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			if (board[i][j] != '*')
			{
				int mineNum = 0;
				int x, y, xMax, yMax;
				if (j == 0) x = 0; else x = -1;
				if (i == 0) y = 0; else y = -1;
				if (j == 9) xMax = 1; else xMax = 2;
				if (i == 9) yMax = 1; else yMax = 2;

				for (int h = y; h < yMax; h++)
				{
					for (int w = x; w < xMax; w++)
					{
						if (board[i + h][j + w] == '*') ++mineNum;
					}
				}

				board[i][j] = '0' + mineNum;
			}
		}
	}

	//보드 확인용 출력
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			printf("%c", board[i][j]);					//그 외에는 지뢰 X
		}
		printf("\n");
	}

	
	//스크린 초기화
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			screen[i][j] = '+';	//스크린을 초기화
		}
	}

	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			printf("%c", screen[i][j]);					//그 외에는 지뢰 X
		}
		printf("\n");
	}

	// 지뢰찾기 게임 순서
	// 0. 초기화 및 기본 화면 출력
	// ======여기부터 반복======
	// 1. 플레이어 입력
	// 2. 해당 좌표와 보드 확인
	// ------지뢰일 경우------
	// 3. 보드를 전부 밝히고 게임 종료
	// ------지뢰가 아닐 경우------
	// 3. 주변에 지뢰가 0일 경우 주변 쫙 확인
	// 3-1. 숫자일 경우 해당 칸만 확인
	// ==========================

	while (isAlive)	//살아있으면 계속 실행	
	{
		printf("\n\n\n");
		int inputX = -1, inputY = -1;
		printf("X Y좌표 입력(띄어쓰기로 구분, 1~10): ");
		scanf(" %d %d", &inputX, &inputY);

		isAlive = Dig(inputX, inputY, board, screen);
		for (int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < 10; ++j)
			{
				printf("%c", screen[i][j]);					//그 외에는 지뢰 X
			}
			printf("\n");
		}

	}
	

	return 0;
}