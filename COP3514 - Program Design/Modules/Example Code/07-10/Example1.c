#include <stdio.h>
#include <stdlib.h>
	
int main()
{
	int* array=NULL;
	int N,i;
	printf("Please enter N: \n"); 	//ask the user to input a number N
	scanf("%d",&N);			//read the number N
	array=(int*) malloc(N*sizeof(int));	//allocate memory for the array of numbers

	if(array==NULL)				//check if malloc failed
		return -1;
	for(i=0;i<N;i++)			//read all of the numbers
		scanf("%d",&array[i]);
	free(array);				//free the memory
	array=NULL;
return 0;
}

