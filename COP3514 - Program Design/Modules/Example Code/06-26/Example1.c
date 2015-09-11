#include <stdio.h>
#include <stdlib.h>

//Dynamic int 

int main()
{
	int *p=NULL; //no memory is being allocated 

	printf("Please enter a number: ");

	//we need to allocate memory for this number

	p=malloc (sizeof(int)); 		//allocate memory for 1 int variable
	
	if(p==NULL)				//check if memory has been allocated
	{
		printf("Memory allocation failed\n");
		return -1;
	}

	scanf("%d",p); 				//store the user input in the allocated memory
	printf("You have entered %d\n",*p); 	//show the number

	free(p);				//deallocate the memory
	p=NULL;

	return 0;

}
