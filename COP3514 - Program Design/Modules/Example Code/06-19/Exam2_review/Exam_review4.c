#include <stdio.h>

void up()
{
	//
	static int x=1;
	printf("%d\n",x);
	x++;
}

int main()
{
	up();
	up();
	up();
	return 0;
}

/*
Output should be:
1
2
3
*/
