#include "Lists.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
The Insert function creates and inserts a new node in the List at a certain _position with a certain _value.
If there is malloc error or the position is invalid the function returns 0, otherwise it returns 1.
You can insert a new node in any existing position or at the end of the List.
*/
int Insert(List** pList,int _position,int _value)
{

	List *temp=(List*) malloc (sizeof(List)); //element to be inserted 
			
	if(temp==NULL)
	{
		return 0;
	}
		
	if(_position<0)
		return 0;
	
	temp->value=_value;

	if(*pList==NULL)
	{
		if(_position!=0)
		{
			free(temp); //no insertion
			return 0;
		}
		temp->next=NULL;
		*pList=temp;
		return 1;
	}
	
	if(_position==0)
	{
		temp->next=*pList;
		*pList=temp;
		return 1;
	}

	List* temp1=*pList;
	int i=0;
	for(i=0;i<(_position-1);i++)
	{
		if(temp1==NULL)
		{
			free(temp); //no insertion
			return 0;
		}
		temp1=temp1->next;
	}

	temp->next=temp1->next;
	temp1->next=temp;
	
	return 1;
}

/*
The Move function moves a node from existing _position1 to a new _position2.
If there is malloc error or the positions are invalid the function returns 0, otherwise it returns 1.
You can move a node from any existing position to any other existing position.
*/
int Move(List** pList,int _position1,int _position2)
{
	if(*pList==NULL)
		return 0;

	if((_position1<0)||(_position2<0))
		return 0;

	if(_position1==_position2)
		return 1;

	List* temp1=*pList;
	List* temp2=*pList;


	int i=0;
	for(i=0;i<(_position1-1);i++)
	{
		if((temp1==NULL)||(temp1->next==NULL))
		{
			return 0;
		}
		temp1=temp1->next;
	}
	if((temp1==NULL)||(temp1->next==NULL))
	{
			return 0;
	}
	List* temp=temp1->next;


	for(i=0;i<_position2;i++)
	{
		if((temp2==NULL)||(temp2->next==NULL))
		{
			return 0;
		}
		temp2=temp2->next;
	}
	
	if(_position1==0)
		*pList=(*pList)->next;

	if(_position2==0)
	{
		temp1->next=temp->next;
		temp->next=temp2;
		*pList=temp;
		return 1;
	}

	if(_position1==0)
	{
		temp1->next=temp2->next;
		temp2->next=temp1;
		return 1;
	}

	temp1->next=temp->next;
	temp->next=temp2->next;
	temp2->next=temp;
	return 1;
}

/*
The Merge function merges 2 existing nodes at _position1 and _position2 by adding their values and
making them one node.
If there is malloc error or the positions are invalid the function returns 0, otherwise it returns 1.
In order to merge 2 nodes they have to be neighboors and both of them have to exist.
*/
int Merge(List** pList,int _position1,int _position2)
{
	if(*pList==NULL)
		return 0;

	if((_position1<0)||(_position2<0))
		return 0;

	if(((_position1-_position2)!=1)&&((_position2-_position1)!=1))
		return 0;

	if(_position1==_position2)
		return 1;

	int pos1=_position1;
	int pos2=_position2;

	if(_position2<_position1)
	{
		pos1=_position2;
		pos2=_position1;
	}

	List* temp=*pList;


	int i=0;
	for(i=0;i<pos1;i++)
	{
		if(temp==NULL)
		{
			return 0;
		}
		temp=temp->next;
	}
	
	if(temp->next==NULL)
		return 0;

	List* temp1=temp->next;
	temp->value+=temp1->value;
	temp->next=temp1->next;
	free(temp1);
	return 1;
}

/*
The Delete function deletes an existing node from a certain _position.
If there is malloc error or the position is invalid the function returns 0, otherwise it returns 1.
*/
int Delete(List** pList,int _position)
{

	if(*pList==NULL)
		return 0;

	if(_position<0)
		return 0;

	
	List* temp=*pList;

	
	if(_position==0)
	{

		*pList=(*pList)->next;
		free(temp);
		return 1;
	}
	int i=0;
	for(i=0;i<(_position-1);i++)
	{
		if(temp==NULL)
		{
			return 0;
		}
		temp=temp->next;
	}
	
	if(temp->next==NULL)
		return 0;

	List* temp1=temp->next;
	temp->next=temp1->next;
	free(temp1);
	return 1;
}

/*
The Print function prints the values of all nodes in the list starting from the first node.
An example of a Print output would be:
1 2 3 4 5 6 7 8 9 10
*/
void Print(List* pList)
{
	List* temp=pList;
	while(temp!=NULL)
	{
		printf("%d ",temp->value);
		temp=temp->next;
	}
	printf("\n");
}


