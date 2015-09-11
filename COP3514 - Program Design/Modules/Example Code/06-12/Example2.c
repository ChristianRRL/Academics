#include <stdio.h>
#include <string.h>

void Room1()
{
	static int x=10;
	x++;
	printf("In Room1 x=%d\n",x);
}


void Room2()
{
	int x=20;
	x++;
	printf("In Room2 x=%d\n",x);

}

int main()
{
	Room1();
	Room2();

	Room1();
	Room2();
	return 0;
}
