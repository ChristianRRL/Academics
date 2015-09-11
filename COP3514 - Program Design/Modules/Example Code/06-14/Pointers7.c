#include <stdio.h>

int main ( )
{
	int some_numbers[] = {101, 102, 103, 104, 105};
	int length = sizeof(some_numbers) / sizeof(some_numbers[0]);
	int i;
	int* pNumber = some_numbers;
	for (i = 0; i < length; i++)
	{
		printf ("Entry %d contains %d\n", i, pNumber[i] );
	}
	
	return 0;
}

