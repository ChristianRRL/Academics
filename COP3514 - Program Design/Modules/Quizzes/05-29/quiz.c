#include <stdio.h>

int main()
{
	int i,j;
	int A[3][4]={{1,1,1,1},{2,2,2,2},{3,3,3,3}};
	
	for (i = 0; i < 3; i++)
	{
		A[i][i]=A[i][i]+1;
	}

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("%d \t",A[i][j]);
		}
		printf("\n");
	}
	return 0;
}

