#include <stdio.h>


int main()
{
	int N;
	int array[100];
	printf("please enter N\n");
	scanf("%d",&N);
	int i;
	if((N<=100)&&(N>0))
	{
		for(i=0;i<N;i++)
		{
			scanf("%d",&array[i]);
		}
	}
	
	return 0;
}
