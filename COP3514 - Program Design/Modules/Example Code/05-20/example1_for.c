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
	int i;
	/* Loop counter */
	printf( "This program computes the sum of integers 1 to N.\n" );
	printf( "Please enter the value for N: ");
	scanf ("%d", &limit);

	for (i=1;i <= limit;i++)
	{
		sum = sum + i; 
		//printf ("Iteration i=%d sum=%d\n",i, sum);

		//i = i + 1; //usually we do not do condition update inside for
		
	}
	
	printf ("The sum is %d\n", sum);
	return 0;
}

