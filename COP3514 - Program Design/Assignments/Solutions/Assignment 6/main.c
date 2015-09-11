#include "Lists.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main()
{
	List* myList;

	FILE *in =fopen("Lists.in","r");
	FILE *out =fopen("Lists.out","w");
	int N;
	int info;
	char command[100];
	int p1;
	int p2;
	int i;

	fscanf(in,"%d\n",&N);

	for(i=0;i<N;i++)	
	{	
		fscanf(in,"%d ",&info);
		Insert(&myList,i,info);
	}
	
	List* temp1=myList;
	while(temp1!=NULL)
	{
		fprintf(out,"%d ",temp1->value);
		temp1=temp1->next;
	}
	fprintf(out,"\n");
		

	while(fscanf(in,"%s %d %d\n",command,&p1,&p2)==3)
	{

		//printf("%s %d %d\n",command,p1,p2);
		//Print(myList);
		if(strcmp(command,"Insert")==0)
		{
		//	printf("Inserting\n");
			Insert(&myList,p1,p2);
		}
		else if(strcmp(command,"Move")==0)
		{
		//	printf("Moving\n");
			Move(&myList,p1,p2);
		}
		else if(strcmp(command,"Merge")==0)
		{
		//	printf("Merging\n");
			Merge(&myList,p1,p2);
		}
		else if(strcmp(command,"Delete")==0)
		{
		//	printf("Deleting\n");
			Delete(&myList,p1);
		}
		//Print(myList);
		temp1=myList;
		while(temp1!=NULL)
		{
			fprintf(out,"%d ",temp1->value);
			temp1=temp1->next;
		}
		fprintf(out,"\n");
		
	}
	fclose(in);
	fclose(out);
	return 0;
}
