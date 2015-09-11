#include <stdio.h>
#include <limits.h>

int main()
{

	int i=5;
	int k=INT_MAX; //INT_MAX = 2147483647
	for(i=5;i<20;i+=3)
	{

		i++;
		k=k+i;
		printf("i=%d k=%d\n",i,k);
	}

	return 0;
}
