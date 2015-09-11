#include "Lists.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	FILE *f_source = fopen("Lists.in", "r");
	if(f_source==NULL)
	{
		printf("Can't open %s\n", "Lists.in");
		exit(EXIT_FAILURE);
	}
	printf("%s can be opened\n", "Lists.in");
	
	FILE *f_target = fopen("Lists.out", "a");
	if(f_target==NULL)
	{
		printf("Can't open %s\n", "Lists.out");
		exit(EXIT_FAILURE);
	}
	printf("%s can be opened\n", "Lists.out");
	
	
	List *myList=NULL;
	int N;
	fscanf(f_source, "%d\n", &N);
	
	int number, i;
	for (i=0;i<N;i++)
	{
		fscanf(f_source, "%d ", &number);
		Insert(&myList,i,number);
	}
	
	char command[100];
	int parameter1, parameter2;
	

	Print(myList);
	while(fscanf(f_source,"%s %d %d\n",command,&parameter1,&parameter2)==3)
	{
		if(strcmp(command,"Insert")==0)
		{
			printf("Insert Function: ");
			Insert(&myList,parameter1,parameter2);
			Print(myList);
			while(myList!=NULL)
			{
				fprintf(f_target,"%d ",myList->value);
				myList=myList->next;
			}
			fprintf(f_target,"\n");
		}
		if(strcmp(command,"Move")==0)
		{
			printf("Move Function:   ");
			Move(&myList,parameter1,parameter2);
			Print(myList);
			while(myList!=NULL)
			{
				fprintf(f_target,"%d ",myList->value);
				myList=myList->next;
			}
			fprintf(f_target,"\n");
		}
		if(strcmp(command,"Merge")==0)
		{
			printf("Merge Function:  ");
			Merge(&myList,parameter1,parameter2);
			Print(myList);
			while(myList!=NULL)
			{
				fprintf(f_target,"%d ",myList->value);
				myList=myList->next;
			}
			fprintf(f_target,"\n");
		}
		if(strcmp(command,"Delete")==0)
		{
			printf("Delete Function: ");
			Delete(&myList,parameter1);
			Print(myList);
			while(myList!=NULL)
			{
				fprintf(f_target,"%d ",myList->value);
				myList=myList->next;
			}
			fprintf(f_target,"\n");
		}
	}
	
	//fprintf
	fclose(f_source);
	fclose(f_target);
	
	return 0;
}
