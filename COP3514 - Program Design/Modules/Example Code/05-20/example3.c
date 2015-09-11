#include <stdio.h>

int main()
{
	int i = 0;

	printf("Please enter the number 1\n");
	scanf("%d",&i);

	while (i!=1)
	{
		printf("You did not enter 1!!!\n");
		printf("Please enter the number 1\n");
		scanf("%d",&i);
	}
	printf ("Program complete\n");
	return 0;
}

