//����ã�� �����
//1. �ϴ� 10, 10 ������
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int board[10][10] = { 0 };	//10 * 10 ũ�� ���� ���� �� �ʱ�ȭ
	int numBombs = 15;			//������ ����
	int numBombsOnBoard = 0;	//���� ���忡 ������ ���� ����
	
	srand((unsigned int)time(NULL));

	//���忡 ���� ����
	//���� -1: Ȯ��, 0: ����X, 1: ����
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			int randNum = rand() % 5;
			if (randNum == 1) board[j][i] = 1;		//20���� ���� ������ ���� 1�̸� ����
			else board[j][i] = 0;					//�� �ܿ��� ���� X
		}
	}

	//���� Ȯ�ο� ���
	/*
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			printf("%2d", board[j][i]);					//�� �ܿ��� ���� X
		}
		printf("\n");
	}
	*/



	return 0;
}