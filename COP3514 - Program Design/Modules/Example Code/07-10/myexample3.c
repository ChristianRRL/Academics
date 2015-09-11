#include <stdio.h>
#include <stdlib.h>

#define FILE_NAME "Input.txt"

int main()
{
	FILE *source_fp=fopen(FILE_NAME,"r");
	if(source_fp==NULL)
	{
		printf("Can't open %s\n",FILE_NAME);
		return -1;
	}
	else
		printf("%s can be opened\n",FILE_NAME);
	
	int* array=(int*)malloc(sizeof(int));
	if(array=NULL)
		return -1;
	int number;
	int index,counter=0;;
	
	for(index=0; fscanf(source_fp,"%d\n",&number)==1; index++)
	{
		int* temp=realloc(array,(index+1)*sizeof(int));
		if(temp==NULL)
			return -1;
		array=temp;
		array[index]=number;
		counter++;
	}
	
	for(index=0; index<counter; index++)
		printf("%d ",array[index]);
	printf("\n");
	
	free(array);
	array=NULL;
	
	return 0;
}