#include <stdio.h>


void do_something(int x)
{
	printf("%d\n",x);
	x--;
	if(x>0)
		do_something(x);
}

int main()
{
	int x=10;
	
	do_something(x);
	return 0;
}


