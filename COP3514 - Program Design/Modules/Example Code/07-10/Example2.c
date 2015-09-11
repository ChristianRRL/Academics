#include <stdio.h>
#include <stdlib.h>
	
int main()
{
	int* array=malloc(sizeof(int));			//allocate memory for at least 1 integer (must use malloc before realloc)
	int number,index=0,i;				//initialize the index to 0 meaning we have 0 numbers in the array
	printf("Please enter numbers. Enter 0 to terminate\n");	//Ask the user to input numbers until 0 is entered
	scanf("%d",&number);
	while(number!=0)					//while the user did not enter 0
	{
		int* temp=realloc(array,(index+1)*sizeof(int));	//reallocate memory for the array 
		if(temp==NULL)					//check if realloc failed
			return -1;
		array=temp;					//assign the new memory to array
		array[index]=number;				//set the new number in the array
		index++;					//increase the index
		scanf("%d",&number);				//wait for user input
	}
			
	for(i=0;i<index;i++)					//print the array
		printf("%d ",array[i]);
	printf("\n");
	free(array);						//free the memory
	array=NULL;
return 0;
}

