#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int value;
	struct node *next;
} Node;

void Create(Node **alist,int N)
{
	(*alist)=malloc(sizeof(Node));
	(*alist)->value=N;
	(*alist)->next=NULL;
	
	if(N>0)
		Create(&((*alist)->next),--N);
}

void Insert(Node **alist,int anumber)
{
	if((*alist)==NULL)
	{
		(*alist)=malloc(sizeof(Node));
		if((*alist)==NULL)
		{
			printf("Malloc failed.\n");
			return;
		}
		(*alist)->value=anumber;
		(*alist)->next=NULL;
	}
	else
		Insert(&((*alist)->next),anumber);
}

void Print(Node *alist)
{
	if(alist!=NULL)
	{
		printf("%d ",alist->next);
		if(alist->next!=NULL)
			Print(alist->next);
	}
}

void ReversePrint(Node *alist)
{
	if(alist!=NULL)
	{
		if(alist->next!=NULL)
			Print(alist->next);
		printf("%d ",alist->next);
	}
}

int main()
{
	Node *list=NULL;
	
	Create(&list,7);
	Print(list);
	Insert(&list,8);
	Insert(&list,9);
	Insert(&list,0);
	Print(list);
	Delete(&list,1);
	Print(list);
	ShiftRight(&list);
	ShiftRight(&list);
	ShiftRight(&list);
	ReversePrint(list);
}