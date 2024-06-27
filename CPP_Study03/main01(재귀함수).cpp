//����ã�� �����
//1. �ϴ� 10, 10 ������
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//board���� �Է¹��� x, y��ǥ�� Ȯ���ϴ� �Լ�
bool Dig(int _x, int _y, char _board[][10], char _screen[][10])
{
	//��ǥ�� 1~10���� �Է� �ޱ⿡ 1�� ����
	int X = _x - 1;
	int Y = _y - 1;

	bool val = true;	//��ũ���� ��ȯ�� ��


	if (_board[Y][X] == '*') return false;	//���ڸ� ������ false ��ȯ
	if (X < 0 || X > 9) return false;
	if (Y < 0 || Y > 9) return false;

	if (_screen[Y][X] != '+') return true;	//�̹� Ȯ���� ĭ�̸� 0��ȯ
	
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
	char board[10][10] = { 0 };	//10 * 10 ũ�� ���� ���� �� �ʱ�ȭ
	char screen[10][10] = { 0 };	//ȭ�鿡 ����� ��ũ��
	int numBombs = 0;			//������ ����
	int numBombsOnBoard = 0;	//���� ���忡 ������ ���� ����

	int isAlive = 1;
	
	srand((unsigned int)time(NULL));

	//���� ����
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			int randNum = rand() % 8;
			if (randNum == 1) board[i][j] = '*';		//20���� ���� ������ ���� 1�̸� ���ڤ���
			else board[i][j] = '0';
		}
	}

	//���ڿ� ���缭 ���� ���� ����
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

	//���� Ȯ�ο� ���
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			printf("%c", board[i][j]);					//�� �ܿ��� ���� X
		}
		printf("\n");
	}

	
	//��ũ�� �ʱ�ȭ
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			screen[i][j] = '+';	//��ũ���� �ʱ�ȭ
		}
	}

	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			printf("%c", screen[i][j]);					//�� �ܿ��� ���� X
		}
		printf("\n");
	}

	// ����ã�� ���� ����
	// 0. �ʱ�ȭ �� �⺻ ȭ�� ���
	// ======������� �ݺ�======
	// 1. �÷��̾� �Է�
	// 2. �ش� ��ǥ�� ���� Ȯ��
	// ------������ ���------
	// 3. ���带 ���� ������ ���� ����
	// ------���ڰ� �ƴ� ���------
	// 3. �ֺ��� ���ڰ� 0�� ��� �ֺ� �� Ȯ��
	// 3-1. ������ ��� �ش� ĭ�� Ȯ��
	// ==========================

	while (isAlive)	//��������� ��� ����	
	{
		printf("\n\n\n");
		int inputX = -1, inputY = -1;
		printf("X Y��ǥ �Է�(����� ����, 1~10): ");
		scanf(" %d %d", &inputX, &inputY);

		isAlive = Dig(inputX, inputY, board, screen);
		for (int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < 10; ++j)
			{
				printf("%c", screen[i][j]);					//�� �ܿ��� ���� X
			}
			printf("\n");
		}

	}
	

	return 0;
}