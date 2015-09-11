#include <stdio.h>
#include <string.h>

void Room1(int *pX)
{
	(*pX)=(*pX)+1;
}

void Room2(int pX)
{
	pX=pX+1;
}

int main()
{
	int x=10;
	Room2(x);
	printf("After room2 x=%d\n",x);
	Room1(&x);
	printf("After room1 x=%d\n",x);
	return 0;
}
