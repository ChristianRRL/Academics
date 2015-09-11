#include <stdio.h>

//use only pointers
void increment(int *startAddr)
{
	int *endAddr=startAddr+10;
	while(startAddr<endAddr)
	{
		(*startAddr)++;
		startAddr++;
	}
}

int main()
{
	int array[10]={1,2,3,4,5,6,7,8,9,10};
	int i;
	increment(array);
	for(i=0;i<10;i++)
		printf("%d ",array[i]);
	printf("\n");
	return 0;
}

/*
Output should be:
2 3 4 5 6 7 8 9 10 11
*/
