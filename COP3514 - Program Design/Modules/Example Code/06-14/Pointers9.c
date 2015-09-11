#include <stdio.h>

int main ( )
{
	int some_numbers[] = {100, 200, 300, 400, 500};
	int* pNumber = some_numbers; 
	int* pNumber2 = &some_numbers[2];
	int diff = pNumber2 - pNumber;
	int diff1 = *pNumber2 - *pNumber;
	printf ("Difference between index entry is %d\n", diff);
	printf ("Difference between element values is %d\n", diff1);
	return 0;
}

