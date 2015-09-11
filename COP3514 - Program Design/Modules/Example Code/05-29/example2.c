#include <stdio.h>

int main()
{
	int i;
	int a[10] = {0,1,2,3,4,5,6,7,8,9};
	for (i = 1; i <= 12; i++)
	{
		printf ("i = %d a[%d] = %d\n", i, i, a[i]);
		a[i] = 0;
	}
	return 0;
}

