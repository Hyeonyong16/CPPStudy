#include <stdio.h>

int main()
{
	//���ﰢ��
	{
		int num = 5;	//ũ��
		int i = 0, j = 0;
		
		for (i = 0; i < num; ++i)
		{
			for (j = i; j < num; ++j)
			{
				printf("*");
			}
			if(i != (num - 1)) printf("\n");	//������ ���� ������� X
		}
	}

	printf("\n");
	
	//���ﰢ��(�Ƕ�̵�)
	{
		int num = 5;	//ũ��
		int i = 0, j = 0;

		for (i = 0; i < num; ++i)
		{
			for (j = 0; j < num - i - 1; ++j)
			{
				printf(" ");
			}
			for (j = 0; j < 2 * i + 1; ++j)
			{
				printf("*");
			}

			if (i != (num - 1)) printf("\n");	//������ ���� ������� X
		}
	}

	return 0;
}