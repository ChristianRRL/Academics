#include <stdio.h>
#include <string.h>

void Room1(int *pX,int *pY,int *pZ)
{
	(*pX)++;
	(*pY)++;
	(*pZ)++;
}


int main()
{
	int x=10, y=20, z=30;
	Room1(&x,&y,&z);
	printf("x=%d y=%d z=%d \n",x,y,z);
	return 0;
}
