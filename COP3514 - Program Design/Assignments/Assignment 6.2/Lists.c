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
	if((*pList)==NULL)
	{
		(*pList)=malloc(sizeof(List));
		if((*pList)==NULL)
			return 0;
		(*pList)->value=_value;
		(*pList)->next=NULL;
		return 1;
	}
	else
	{
		List *temp1=malloc(sizeof(List));
		temp1->value=_value;
		
		if(_position==0)
		{
			temp1->next=(*pList)->next;
			*pList=temp1;
			return 1;
		}
		else
		{
			List *temp2=*pList;
			int i;
			for(i=0; i<(_position-1); i++)
			{
				if(temp2==NULL)
					return 0;
				temp2=temp2->next;
			}
			temp1->next=temp2->next;
			temp2->next=temp1;
			return 1;			
		}
	}
	return 0;
}

/*
The Move function moves a node from existing _position1 to a new _position2.
If there is malloc error or the positions are invalid the function returns 0, otherwise it returns 1.
You can move a node from any existing position to any other existing position.
*/
int Move(List** pList,int _position1,int _position2)
{
	if((*pList)==NULL)
		return 0;
	else
	{
		List *temp1=*pList;
		List *temp2=*pList;
		List *temp=*pList;
		int i;
		
		if(_position1==0)			//ERRORS
		{
			/*
			for(i=0;i<_position2;i++)
			{
				if(temp2==NULL)
					return 0;
				temp=temp2;
				temp2=temp2->next;
			}
			
			//temp1->next=temp2;
			printf("\ntemp1=%d\n",temp1->value);
			printf("temp2=%d\n",temp2->value);
			printf("temp=%d\n",temp->value);
			printf("(*pList)->value=%d\n",(*pList)->value);
			
			temp->next=temp2->next;
			temp1->next=temp2->next;
			(*pList)=(*pList)->next;
			//////temp2->next=temp1;
			////temp1->next=temp2->next;
			////temp2->next=(*pList)->next;
			////(*pList)=temp2;
			//temp->next=temp1;
			//temp2->next=(*pList)->next;
			//*pList=temp2;
			//free(temp1);
			//temp1=NULL;
			
			
			//*pList=(*pList)->next;
			//temp1->next=temp2->next;
			//temp2->next=temp1;
			*/
			return 1;
		}
		if(_position2==0)
		{
			
		}
		if(_position1==0 && _position2==0)
			return 0;
		
		for(i=0;i<_position1;i++)
		{
			if(temp1==NULL)
				return 0;
			temp=temp1;
			temp1=temp1->next;
		}
		
		for(i=0;i<_position2;i++)
		{
			if(temp2==NULL)
				return 0;
			temp2=temp2->next;
		}
		
		temp->next=temp1->next;
		temp1->next=temp2->next;
		temp2->next=temp1;
		
		return 1;
	}
	return 0;
}

/*
The Merge function merges 2 existing nodes at _position1 and _position2 by adding their values and
making them one node.
If there is malloc error or the positions are invalid the function returns 0, otherwise it returns 1.
In order to merge 2 nodes they have to be neighboors and both of them have to exist.
*/
int Merge(List** pList,int _position1,int _position2)
{
	if((*pList)==NULL)
		return 0;
	else
	{
		List *temp1=*pList;
		List *temp2=*pList;
		int pos1=_position1;
		int pos2=_position2;
		int i;
		
		if(_position2<_position1)
		{
			pos1=_position2;
			pos2=_position1;
		}
		if((pos2-pos1)==1)
		{
			for(i=0;i<pos1;i++)
			{
				if(temp1==NULL)
					return 0;
					
				temp1=temp1->next;
			}
			
			for(i=0;i<pos2;i++)
			{
				if(temp2==NULL)
					return 0;
					
				temp2=temp2->next;
			}
			
			temp1->value+=temp2->value;
			temp1->next=temp2->next;
			free(temp2);
			temp2=NULL;
			
			return 1;
		}
		else
			return 0;
	}
	return 0;
}

/*
The Delete function deletes an existing node from a certain _position.
If there is malloc error or the position is invalid the function returns 0, otherwise it returns 1.
*/
int Delete(List** pList,int _position)
{
	if((*pList)==NULL)
		return 0;
	else
	{
		List *temp1=*pList;
		List *temp2=*pList;
		int i;
		
		for(i=0;i<_position;i++)
		{
			if(temp1==NULL)
				return 0;
			if(temp2==NULL)
				return 0;
			temp1=temp2;
			temp2=temp2->next;
		}
		
		if(_position==0)
		{
			(*pList)=(*pList)->next;
			free(temp2);
			temp2=NULL;
			return 1;
		}
		else
		{
			temp1->next=temp2->next;
			free(temp2);
			temp2=NULL;
			return 1;
		}
	}
	return 0;
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


