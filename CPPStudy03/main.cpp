//���ٿ� ���� �����
//��� �Լ��� ���� �����غ���

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int CheckNumber(int _a)
{
	int input = -1;	//�ʱ�ȭ
	//���� �� ���� �Է½ÿ��� �ٽ� �Է��ϰ� �ݺ�
	//���� �� ���� �Է��ϸ� ����
	while (input > 99 || input < 0) {
		printf("0~99���� ���ڸ� �ϳ� �Է����ּ���: ");
		scanf(" %d", &input);
	}

	//�Է��� ���ڰ� �� ������ �۴ٰ� ���
	if (input < _a)
	{
		printf("%d�� ���ڰ� �� �۽��ϴ�.\n", input);
		CheckNumber(_a);
	}

	//�Է��� ���ڰ� �� ũ�� ũ�ٰ� ���
	else if (input > _a)
	{
		printf("%d�� ���ڰ� �� Ů�ϴ�.\n", input);
		CheckNumber(_a);
	}

	//�Է��� ���ڶ� ������ �ش� ���ڸ� ��ȯ
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
		int num = rand() % 100;		//������ ���� ����
		num = CheckNumber(num);		//���� üũ�ϴ� ����Լ� ����

		printf("%d�� �����Դϴ�.\n", num);		//���� ����
		printf("0�� �Է��ϸ� ����, �ٸ� Ű�� �Է��ϸ� �ѹ� �� �����մϴ�.\n ");		//0�Է½� ����, �� �ܴ� ����

		scanf(" %d", &input);
	}

	return 0;
}