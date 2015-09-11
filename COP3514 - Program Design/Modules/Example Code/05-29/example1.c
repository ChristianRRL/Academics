#include <stdio.h>

int main ( )
{
	int numbers[5];
	int i;
	for(i=0;i<5;i++)
	{
		numbers[i]=i;
	}
	for(i=0;i<5;i++)
	{
		printf("numbers[%d]=%d \n",i,numbers[i]);
	}
	return 0;
}

