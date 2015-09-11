#include <stdio.h>

int main()
{
	int a = 1;
	int b = 0;

	printf ("*************Correct********************\n");
	printf ("\nBefore \"if\" a=%d and b=%d \n\n", a, b);

	if (a == b) //correct
	{
		printf ("a and b are equal\n\n");
	}
	else
	{
		printf ("a and b are unequal\n\n");
	}
	
	printf ("After \"if\" a=%d and b=%d\n\n", a, b);
	printf ("*****************************************\n\n");

	printf ("***************Incorrect****************\n");
	printf ("\nBefore \"if\" a=%d and b=%d \n\n", a, b);

	if (a = b) //incorect 
	{
		printf ("a and b are equal\n\n");
	}
	else
	{
		printf ("a and b are unequal\n\n");
	}
	
	printf ("After \"if\" a=%d and b=%d\n\n", a, b);
	printf ("*****************************************\n\n");
	return 0;
}

