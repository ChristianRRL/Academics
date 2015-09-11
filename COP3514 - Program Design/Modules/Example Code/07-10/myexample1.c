#include <stdio.h>
#include <stdlib.h>

//Dynamic int 

int main()
{
	int *array=NULL;			//set array elements to NULL
	int N,i;			//declare variables
	printf("Please enter a number N:\n");
	scanf("%d",&N);
	array=(int*)malloc(N*sizeof(int));			//allocate memory for array
	if(array==NULL)			//validate memory allocation
	{
		printf("MEMORY ALLOCATION FAILED.\n");
		return -1;
	}
	printf("Please enter each element in the N numbered array:\n");
	for(i=0; i<N; i++)			//scan each element into the array
	{
		scanf("%d",&array[i]);
	}
	for(i=0; i<N; i++)			//read each element of the array
	{
		printf("%d ",array[i]);
	}
	printf("\n");
	free(array);			//free allocated memory
	array=NULL;			//set array elements back to NULL
	
	return 0;
}