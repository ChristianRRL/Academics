#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Dynamic memory: show, create, search and delete 
//Very useful for Assignment 5

typedef struct Dream
{
	int number;
	struct Dream* nextDream;
}Dream;

void Inception(Dream *dream)
{
	if(dream!=NULL)
	{
		printf("%d,%p ",dream->number,dream);
		if(dream->nextDream!=NULL)
		{
			Inception(dream->nextDream);
		}
	}
}



int creatDream(Dream **pDream,int n)
{
	if((*pDream)==NULL)
	{
		*pDream=(Dream*) malloc (sizeof(Dream));
		if((*pDream)==NULL)
		{
			printf("Malloc failed\n");
			return 0;
		}
		(*pDream)->number=n;
		(*pDream)->nextDream=NULL;
		return 1;
	}
	else
	return creatDream(&((*pDream)->nextDream),n);
}

void showDreamNumber(Dream *pDream,int _n)
{
	if(pDream==NULL)
	{
		printf("Number not found\n");
	}
	else
	{	
		if(pDream->number==_n)
		{
			printf("The number is %d\n",pDream->number);
		}
		else
			showDreamNumber(pDream->nextDream,_n);
	}
}

int delete(Dream **pDream,int _n)
{
	if((*pDream)->number==_n)
	{
		Dream* temp=(*pDream);
		(*pDream)=(*pDream)->nextDream;
		free(temp);
		temp=NULL;
		return 1;
	}
	else
	{
		Dream* temp=(*pDream);
		Dream* temp1=(*pDream);
		while((temp!=NULL)&&(temp->number!=_n))
		{
			temp1=temp;
			temp=temp->nextDream;
		}
		if(temp!=NULL)
		{
			temp1->nextDream=temp->nextDream;
			free(temp);
			temp=NULL;
			return 1;
		}
		else
			return 0;
		
	}
	return 0;
}

int main()
{
	 
	Dream *firstDream=NULL;

	creatDream(&firstDream,5);
	creatDream(&firstDream,7);
	creatDream(&firstDream,10);

	showDreamNumber(firstDream,11);
	showDreamNumber(firstDream,7);
	printf("\n");
	Inception(firstDream);
	printf("\n");
	delete(&firstDream,7);
	printf("\n");
	Inception(firstDream);
	printf("\n");
	return 0;

}
