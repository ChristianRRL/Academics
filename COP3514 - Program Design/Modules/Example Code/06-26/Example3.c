#include <stdio.h>
#include <stdlib.h>

//Dynamic 2D int array. 

int main()
{
	 
	int **array=NULL; //no memory is being allocated 

	int row=0; 
	int column=0; 
	int i,j;

	printf("Please enter number of rows: ");

	scanf("%d",&row);

	printf("Please enter number of columns: ");

	scanf("%d",&column);

	//we need to allocate memory for the array 

	array=malloc (row*sizeof(int)); 		//allocate memory for the array rows

	if(array==NULL)				//check if memory has been allocated
	{
		printf("Memory allocation failed\n");
		return -1;
	}
	
	//allocate memory for the array columns

	for(i=0;i<row;i++)
	{
		array[i]=malloc (column*sizeof(int));
			
		if(array[i]==NULL)				//check if memory has been allocated
		{
			printf("Memory allocation failed\n");
			return -1;
		}
	} 

	for(i=0;i<row;i++)
	{
		for(j=0;j<column;j++)
		{		
			scanf("%d",&array[i][j]); 				//store the user input in the allocated memory
		}
	}

	printf("You have entered :\n"); 	//show the array
	for(i=0;i<row;i++)
	{
		for(j=0;j<column;j++)
		{		
			printf("%d ",array[i][j]); 			
		}
		printf("\n");
	}
	printf("\n");

	//deallocate the memory for the columns
	for(i=0;i<column;i++)
	{
		free(array[i]);				
		array[i]=NULL;	
	}

	//deallocate the memory for the rows
	free(array);	
	array=NULL;

	return 0;

}
