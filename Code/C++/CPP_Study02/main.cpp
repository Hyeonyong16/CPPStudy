#include <stdio.h>

int main()
{
	//역삼각형
	{
		int num = 5;	//크기
		int i = 0, j = 0;
		
		for (i = 0; i < num; ++i)
		{
			for (j = i; j < num; ++j)
			{
				printf("*");
			}
			if(i != (num - 1)) printf("\n");	//마지막 줄은 개행실행 X
		}
	}

	printf("\n");
	
	//정삼각형(피라미드)
	{
		int num = 5;	//크기
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

			if (i != (num - 1)) printf("\n");	//마지막 줄은 개행실행 X
		}
	}

	return 0;
}