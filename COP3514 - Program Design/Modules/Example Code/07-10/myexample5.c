#include <stdio.h>
#include <stdlib.h>
#include <string.h>
	
typedef struct node
{
	int info;
	struct node* next;
}Node;

//Shift all node elements to the right
void ShiftRight(Node** list)
{
	Node* first = *list;
	Node* last =*list;
	Node* temp =*list;
	if(*list!=NULL)
	{
		while(last->next!=NULL)
		{
			temp=last;
			last=last->next;
		}
		printf("\ntemp is %d\n",temp->info);	//temp is the second to last element
		printf("last is %d\n",last->info);
		printf("first is %d\n\n",first->info);	
	
		//reorganize the list	
		last->next=first;	
		temp->next=NULL;
		*list=last;
	}
	else
		return;
}

//Shift all node elements to the left
void ShiftLeft(Node** list)
{
	Node* first=*list;
	Node* last=*list;
	Node* temp=*list;
	if(*list!=NULL)
	{
		while(last->next!=NULL)
			last=last->next;
		temp=temp->next;
		
		printf("\ntemp is %d\n",temp->info);	//temp is the second to last element
		printf("last is %d\n",last->info);
		printf("first is %d\n\n",first->info);
		
		//reorganize the list
		last->next=first;
		first->next=NULL;
		*list=temp;
	}
}

void insert(Node **alist,int N)
{
	if((*alist)==NULL)
	{
		(*alist)=malloc(sizeof(Node));
		if(*alist==NULL)
		{
			printf("Malloc failed.\n");
			return;
		}
		(*alist)->info=N;
		(*alist)->next=NULL;
	}
	else
		insert(&((*alist)->next),N);
}

void print(Node *list)
{
	Node* temp=list;
	while(temp!=NULL)
	{
		printf("%d ",temp->info);
		temp=temp->next;
	}
	printf("\n");
}

int main()
{
	Node* list;
	insert(&list,1);
	insert(&list,2);
	insert(&list,3);
	insert(&list,4);
	insert(&list,5);
	print(list);
	printf("Shift list to the right 3 times:\n");
	ShiftRight(&list);
	print(list);
	ShiftRight(&list);
	print(list);
	ShiftRight(&list);
	print(list);
	printf("Shift list to the left 2 times:\n");
	ShiftLeft(&list);
	print(list);
	ShiftLeft(&list);
	print(list);
return 0;
}