#include <stdio.h>
#include <string.h>

void swap(int *number1,int *number2)
{
	int temp;
	if(*number1>*number2)
	{
		temp=*number1;
		*number1=*number2;
		*number2=temp;
	}
}


int main()
{
	int x=10,y=5;
	swap(&x,&y);
	printf("x=%d y=%d  \n",x,y);
	return 0;
}
