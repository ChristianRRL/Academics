#include <stdio.h>

int main()
{
	int i,j;
	int A[3][4]={{1,10,100,1000},{2,2,2,2},{3,30,300,3000}};
	int B[3][4]={{1,10,100,1000},{2,20,200,2000},{3,30,300,3000}};
	int C[3][4];
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
		{
			C[i][j]=A[i][j]+B[i][j];
			printf("%d \t",C[i][j]);
		}
		printf("\n");
	}
	return 0;
}

