#include <stdio.h>
#include <string.h>

#define DEBUG 1

void Room1(int *pX)
{
	if(pX!=NULL)
	{
		(*pX)++;
	}
	else if(DEBUG)
	{
		printf("Seg fault\n");
	}
}


int main()
{
	int x=10;
	int* pointer=&x;

	Room1(pointer);
	printf("x=%d\n",x);
	return 0;
}
