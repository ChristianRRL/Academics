#include <stdio.h>
#include <stdlib.h>
#include <string.h>
	
int main()
{
	FILE *f=fopen("Input1.txt","r");	//open file Input1.txt for reading

	char** array=(char**)malloc(sizeof(char*)); //allocate memory for at least 1 char pointer (must use malloc before realloc)
	int number,index=0,i;			    //initialize the index to 0 meaning we have 0 numbers in the array
	char string[200];

	while(fscanf(f,"%s\n",string)==1)		//while there is a string in the file read it and store it in string
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
		index++;					//increase the index
	}

	for(i=0;i<index;i++)	
	{				//print all the strings in the array
		printf("%s ",array[i]);
		free(array[i]);
	}
	printf("\n");
	free(array);						//free the memory
	array=NULL;

return 0;
}

