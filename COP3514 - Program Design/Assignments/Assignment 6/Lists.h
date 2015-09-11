#ifndef _Warehouse13H_
#define _Warehouse13H_

typedef struct node
{
	int value;
	struct node *next;

}List;

/*
The Insert function creates and inserts a new node in the List at a certain _position with a certain _value.
If there is malloc error or the position is invalid the function returns 0, otherwise it returns 1.
You can insert a new node in any existing position or at the end of the List.
*/
int Insert(List** pList,int _position,int _value);

/*
The Move function moves a node from existing _position1 to a new _position2.
If there is malloc error or the positions are invalid the function returns 0, otherwise it returns 1.
You can move a node from any existing position to any other existing position.
*/
int Move(List** pList,int _position1,int _position2);

/*
The Merge function merges 2 existing nodes at _position1 and _position2 by adding their values and
making them one node.
If there is malloc error or the positions are invalid the function returns 0, otherwise it returns 1.
In order to merge 2 nodes they have to be neighboors and both of them have to exist.
*/
int Merge(List** pList,int _position1,int _position2);

/*
The Delete function deletes an existing node from a certain _position.
If there is malloc error or the position is invalid the function returns 0, otherwise it returns 1.
*/
int Delete(List** pList,int _position);

/*
The Print function prints the values of all nodes in the list starting from the first node.
An example of a Print output would be:
1 2 3 4 5 6 7 8 9 10
*/
void Print(List* pList);

#endif
