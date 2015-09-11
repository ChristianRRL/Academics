#include <stdio.h>
#include <string.h>

void Room1()
{
	int x=10;
	printf("In Room1 x=%d\n",x);
}


void Room2()
{
	int x=20;
	printf("In Room2 x=%d\n",x);

}

int main()
{
	int x=0;
	Room1();
	Room2();
	printf("In main x=%d\n",x);
	return 0;
}
