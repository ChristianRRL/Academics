#include <stdio.h>
#include <stdlib.h>

//Dynamic int array

int main()
{
	int *array=NULL; //no memory is being allocated 

	int lenght=0; 	//we can also use dynamic memory allocation for this variable
	int i;

	printf("Please enter the length of the array you wish to create: ");

	scanf("%d",&lenght);

	//we need to allocate memory for the array 

	array=malloc (lenght*sizeof(int)); 		//allocate memory for the array
	
	if(array==NULL)				//check if memory has been allocated
	{
		printf("Memory allocation failed\n");
		return -1;
	}
	for(i=0;i<lenght;i++)
		scanf("%d",&array[i]); 				//store the user input in the allocated memory


	printf("You have entered :\n"); 	//show the array
	for(i=0;i<lenght;i++)
		printf("%d ",array[i]); 			
	printf("\n");


	free(array);				//deallocate the memory

	array=NULL;

	return 0;

}
