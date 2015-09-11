#include <stdio.h>
#include <stdlib.h>
	
int main()
{
	int* array=(int*)malloc(sizeof(int));
	if(array==NULL)
	{
		printf("Memory Allocation Failed.\n");
		return -1;
	}
	int number;
	int counter=0,i;
	printf("Please enter numbers. Enter 0 to terminate\n");	//Ask the user to input numbers until 0 is entered
	scanf("%d",&number);
	for(i=0; number!=0; i++)					//while the user did not enter 0
	{
		int* temp=realloc(array,(i+1)*sizeof(int));	//reallocate memory for the array 
		if(temp==NULL)					//check if realloc failed
			return -1;
		array=temp;					//assign the new memory to array
		array[i]=number;				//set the new number in the array
		counter++;					//increase the index
		scanf("%d",&number);				//wait for user input
	}
			
	for(i=0;i<counter;i++)					//print the array
		printf("%d ",array[i]);
	printf("\n");
	free(array);						//free the memory
	array=NULL;
return 0;
}

