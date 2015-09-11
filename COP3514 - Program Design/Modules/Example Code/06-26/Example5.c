#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Dynamic structure

typedef struct Dream
{
	int number;
	struct Dream* dream;
}Dream;


void createInception(Dream** adream,int N) 
{

	(*adream)=malloc (sizeof(Dream));		
	(*adream)->number=N;
	(*adream)->dream=NULL;
	if(N>0)
	createInception(&((*adream)->dream),--N);
	
}

void Inception(Dream *dream)
{
	if(dream!=NULL)
	{
		printf("%d ",dream->number);
		if(dream->dream!=NULL)
		{
			Inception(dream->dream);
		}
	}
}

void reverseInception(Dream *dream)
{
	if(dream!=NULL)
	{
		if(dream->dream!=NULL)
		{
			reverseInception(dream->dream);
		}
		printf("%d ",dream->number);
	}
}

void destroyInception(Dream** dream) 
{

	if((*dream)!=NULL)
	{
		if((*dream)->dream!=NULL)
		{
			destroyInception(&((*dream)->dream));
		}
		free(*dream);
		*dream=NULL;
	}
	
}
int main()
{
	 
	Dream *dream=NULL;

	createInception(&dream,10); 	//create 10 dreams within a dream
	
	//printf("%d\n",dream->dream->dream->dream->dream->dream->dream->dream->dream->dream->dream->number);
	

	printf("Inception: ");
	Inception(dream);		//go through the dreams starting from the first one
	printf("\n\n");

	printf("Reverse Inception: ");
	reverseInception(dream);	//go through the dreams starting from the last one
	printf("\n\n");

	destroyInception(&dream);	//free all memory 

	if(dream==NULL)
	{
		printf("Inception has been destroyed\n");
	}
	return 0;

}
