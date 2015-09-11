#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//

typedef struct node
{
	int info;
	struct node* next;
	struct node* prev;
}Node;



int insert(Node **addressFirst,Node **addressLast,int n)
{
	if((*addressFirst)==NULL)
	{
		*addressFirst=(Node*) malloc (sizeof(Node));
		if((*addressFirst)==NULL)
		{
			printf("Malloc failed\n");
			return 0;
		}
		(*addressFirst)->info=n;
		(*addressFirst)->next=NULL;
		(*addressFirst)->prev=NULL;
		(*addressLast)=(*addressFirst);
		return 1;
	}
	else
	{
		(*addressLast)->next=(Node*) malloc (sizeof(Node));
		if(((*addressLast)->next)==NULL)
		{
			printf("Malloc failed\n");
			return 0;
		}
		(*addressLast)->next->info=n;
		(*addressLast)->next->next=NULL;
		(*addressLast)->next->prev=(*addressLast);
		(*addressLast)=(*addressLast)->next;
		return 1;
	}
}



int delete(Node *q)
{
	if(q->prev!=NULL)
		q->prev->next=q->next;
	if(q->next!=NULL)
		q->next->prev=q->prev;
	free(q);
	q=NULL;
}

void showList(Node *addressFirst)
{
	if(addressFirst!=NULL)
	{
		printf("%d ",addressFirst->info);
		showList(addressFirst->next);
	}
	printf("\n");
}

void showListReverse(Node *addressLast)
{
	Node* temp=addressLast;
	while(temp!=NULL)
	{
		printf("%d ",temp->info);
		temp=temp->prev;
	}
	printf("\n");
}
int main()
{
	 
	Node *first=NULL;
	Node *last=NULL;

	insert(&first,&last,1);
	insert(&first,&last,2);
	insert(&first,&last,3);

	showList(first);
	showListReverse(last);
	
	return 0;

}
