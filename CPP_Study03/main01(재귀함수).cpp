//지뢰찾기 만들기
//1. 일단 10, 10 사이즈
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int board[10][10] = { 0 };	//10 * 10 크기 보드 생성 및 초기화
	int numBombs = 15;			//지뢰의 개수
	int numBombsOnBoard = 0;	//현재 보드에 생성된 지뢰 개수
	
	srand((unsigned int)time(NULL));

	//보드에 지뢰 생성
	//보드 -1: 확인, 0: 지뢰X, 1: 지뢰
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			int randNum = rand() % 5;
			if (randNum == 1) board[j][i] = 1;		//20으로 나눈 나머지 값이 1이면 지뢰
			else board[j][i] = 0;					//그 외에는 지뢰 X
		}
	}

	//보드 확인용 출력
	/*
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			printf("%2d", board[j][i]);					//그 외에는 지뢰 X
		}
		printf("\n");
	}
	*/



	return 0;
}