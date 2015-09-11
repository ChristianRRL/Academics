#include <stdio.h>
#include <string.h>

int y;

void Room1()
{
	printf("In Room1 y=%d\n",y);
	y++;
}


void Room2()
{
	int y=10;
	printf("In Room2 y=%d\n",y);
	y++;

}

int main()
{
	y=0;
	Room1();
	Room2();
	printf("In main y=%d\n",y);
	return 0;
}
