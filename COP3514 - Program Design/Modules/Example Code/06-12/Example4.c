#include <stdio.h>
#include <string.h>

#define DEBUG 0

int main()
{
	int i=0;
	int numbers[100];
	printf("Please enter 100 numbers\n");
	for(i=0;i<100;i++)
	{
		scanf("%d",&numbers[i]);
		if(DEBUG)
		{
			printf("%d\n",numbers[i]);
		}
	}
	printf("Thank you!\n");
	return 0;
}
