#include <stdio.h>
#include <string.h>

void Room1(int *p)
{
	p++;
	(*p)++; //p[0]++;
}


int main()
{
	int array[3]={10,20,30};
	int * pointer=&array[0]; //same as int * pointer=array;
	Room1(pointer);
	printf("a1=%d a2=%d a3=%d \n",array[0],array[1],array[2]);
	return 0;
}
