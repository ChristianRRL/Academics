#include <stdio.h>

int main ( )
{
	int some_numbers[] = {101, 102, 103, 104, 105};
	int* pNumber = some_numbers;
	while (pNumber <= &some_numbers[4])// Continue while pointer inside array
	{
		printf ("value=%d\n", *pNumber ); //Contents of the address that pNumber points to
		printf ("address=%d\n", pNumber );
		pNumber++; //Advance pNumber to next element of the array
	}

	return 0;
}

