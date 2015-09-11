#include <stdio.h>

void Sum_and_Compare(int x, int y, int *sumPtr, int *compPtr)
{
	*sumPtr = x+y;
	if(x>y)
		*compPtr = 1;
	else
		*compPtr = 0;
}

int main()
{
	int i = 0, j = 0, sum = 0, comp = 0;
	printf("Enter two integers\n");
	scanf("%d %d",&i,&j);

	Sum_and_Compare(i,j,&sum,&comp);

	printf("Sum: %d; Compare: %d\n",sum,comp);
	return 0;
}


