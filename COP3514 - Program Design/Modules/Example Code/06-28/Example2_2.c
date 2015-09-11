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
	printf("Please input the numbers: \n");
	for(i=0;i<lenght;i++)
		scanf("%d",&array[i]); 				//store the user input in the allocated memory

	printf("\nThe array is: \n");
	for(i=0;i<lenght;i++)
		printf("%d ",array[i]); 
	printf("\n");

	char response[10];
	int new_lenght;
	int index=i;
	while(1)
	{
		
		printf("Would you like to add more numbers? ");
		scanf("%s",response);
		if(strcmp(response,"yes")==0)
		{

			printf("How many numbers would you like to add?: ");

			scanf("%d",&new_lenght);

			int *temp=NULL;
			temp=(int*)realloc (array,lenght+new_lenght); 		//reallocate memory for the array
	
			if(temp==NULL)				//check if memory has been allocated
			{
				printf("Memory reallocation failed\n");
				return -1;
			}
			else
			{
				array=temp;
				lenght+=new_lenght;
				printf("Please input the numbers: \n");
				for(i=index;i<lenght;i++)
					scanf("%d",&array[i]); 	
				index=i;
				printf("\nNow the array is: \n");
				for(i=0;i<lenght;i++)
					printf("%d ",array[i]); 
				printf("\n");
			}

		}
		else
			break;
	}

	free(array);				//deallocate the memory

	array=NULL;

	return 0;

}
