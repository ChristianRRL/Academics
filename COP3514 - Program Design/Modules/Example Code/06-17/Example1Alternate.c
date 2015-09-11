#include <stdio.h>
#include <string.h>

void Room1(int pX)
{
	(pX)=(pX)+1;
	return;
}

int main()
{
	int x=10;
	Room1(x);
	printf("After room1 x=%d\n",x);
	return 0;
}
