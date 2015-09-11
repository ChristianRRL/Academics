/*
This program computes the sum of an arithmetic series,
1 + 2 + 3 + ... + N, where the value of N is supplied
by the user
*/
#include <stdio.h>

int main()
{
	int limit = 0;
	int sum = 0;
	int i = 1;
	/* Loop counter */
	printf( "This program computes the sum of integers 1 to N.\n" );
	printf( "Please enter the value for N: ");
	scanf ("%d", &limit);

	while (i <= limit)
	{
		sum = sum + i; 
		printf ("Iteration i=%d sum=%d\n",i, sum);

		i = i + 1; //condition update
		
	}
	
	printf ("The sum is %d and i=%d\n", sum,i);
	return 0;
}

