#include <stdio.h>

void print1()
{

	printf("hello\n");

}


void print2()
{

	print1();
}


int main()
{


	print1();
	print2();
	return 0;
}
