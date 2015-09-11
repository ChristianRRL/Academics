#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE *source_fp=fopen("Input1.txt","r");	//open file Input1.txt for reading

	char** array=(char**)malloc(sizeof(char*)); //allocate memory for at least 1 char pointer (must use malloc before realloc)
	char string[200];
	int index,counter=0;			    //initialize the index to 0 meaning we have 0 numbers in the array

	for(index=0; fscanf(source_fp,"%s\n",string)==1; index++)		//while there is a string in the file read it and store it in string
	{
		char** temp=(char**)realloc(array,((index+1)*sizeof(char*)));	//reallocate memory for the array 
		if(temp==NULL)							//check if realloc failed
		{
			printf("ERROR\n");
			return -1;
		}
		array=temp;					//assign the new memory to array
		array[index]=(char*)malloc(strlen(string)+1);	//allocate memory for the string
		strcpy(array[index],string);			//copy the string
		counter++;					//increase the index
	}

	for(index=0;index<counter;index++)	
	{				//print all the strings in the array
		printf("%s ",array[index]);
		free(array[index]);
	}
	printf("\n");
	free(array);						//free the memory
	array=NULL;

return 0;
}

