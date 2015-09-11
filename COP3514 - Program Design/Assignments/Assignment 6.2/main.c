#include "Lists.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int N;						//number of elements in List
	int number;					//element number in List
	int i;						//index
	char s_debug[1000];			//contents of debugging file
	char s_target[1000];		//contents of target file
	char s_source[1000];		//contents of source file
	List *myList=NULL;			//initializes myList of type List
	int parameter1;
	int parameter2;
	
	FILE *f_debug=fopen("Debug.out", "w");		//open Debug.out file
	if(f_debug==NULL)
		return -1;
	
	FILE *f_source=fopen("Lists.in", "r");		//open Lists.in file
	if(f_source==NULL)
	{
		strcat(s_debug,"Cannot open Lists.in file\n");
		fprintf(f_debug,"%s",s_debug);
		return -1;
	}
	else
		strcat(s_debug,"Opened Lists.in file\n");
	
	FILE *f_target=fopen("Lists.out", "a");		//open Lists.out file
	if(f_target==NULL)
	{
		strcat(s_debug,"Cannot open Lists.out file\n");
		fprintf(f_debug,"%s",s_debug);
		return -1;
	}
	else
		strcat(s_debug,"Opened Lists.out file\n");
	
	
	fscanf(f_source,"%d\n",&N);		//reads from f_source
	strcat(s_debug,"Start for loop\n");
	for(i=0;i<N;i++)
	{
		fscanf(f_source,"%d ",&number);
		Insert(&myList,i,number);
		if(i<N-1)
			fprintf(f_target,"%d ",number);
		else
		{
			fprintf(f_target,"%d ",number);
			fprintf(f_target,"\n");
		}
	}
	strcat(s_debug,"End for loop\n");
	
	//fprintf(f_debug,"%s",s_debug);			//print to Debug.out
	Print(myList);
	//fprintf(f_target,"%s",s_target);
	
	strcat(s_debug,"Start while loop\n");
	while(fscanf(f_source,"%s %d %d\n",s_source,&parameter1,&parameter2)==3)
	{
		if(strcmp(s_source,"Insert")==0)
		{
			printf("Insert Function: ");
			Insert(&myList,parameter1,parameter2);
			Print(myList);
			strcat(s_debug,"Called Insert function\n");
		}
		if(strcmp(s_source,"Move")==0)
		{
			printf("Move Function:   ");
			Move(&myList,parameter1,parameter2);
			Print(myList);
			strcat(s_debug,"Called Move function\n");
		}
		if(strcmp(s_source,"Merge")==0)
		{
			printf("Merge Function:  ");
			Merge(&myList,parameter1,parameter2);
			Print(myList);
			strcat(s_debug,"Called Merge function\n");
		}
		if(strcmp(s_source,"Delete")==0)
		{
			printf("Delete Function: ");
			Delete(&myList,parameter1);
			Print(myList);
			strcat(s_debug,"Called Delete function\n");
		}
	}
	strcat(s_debug,"End while loop\n");

	fclose(f_target);
	strcat(s_debug,"Closed List.out file\n");
	fclose(f_source);
	strcat(s_debug,"Closed List.out file\n");
	
	fprintf(f_debug,"%s",s_debug);			//print to Debug.out
	fclose(f_debug);
	
	return 0;
}
