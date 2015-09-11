#include <stdio.h>

int main()
{

	int i=5;
	int sum=0;
	for(i=5;i<20;i+=3)
	{
		sum=sum+i;

		i++;
		printf("i=%d sum=%d\n",i,sum);
	}

	return 0;
}
