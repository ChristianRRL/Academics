#include <stdio.h>

int main()
{
	int i;
	int j;
	for (i = 1; i != 10; i+=2)
	{
		printf ("%3d %6d\n", i, i*i);
	}

	printf ("Program complete\n");
	return 0;
}

