#include <time.h>
#include <stdio.h>

int Fibonacci (int n)
{
	if (n <= 2)
	{
		return 1;
	}
	return Fibonacci(n-1) + Fibonacci(n-2);
}


int main()
{

	int num, fibo;
	time_t start_time, end_time;
	printf ("This program computes Fibonacci numbers\n\n");
	while (1)
	{
		printf ("Enter a (fairly small) integer: ");
		if (scanf("%d", &num) == 1)
		{
			time(&start_time);
			fibo = Fibonacci(num);
			time(&end_time);
			printf ("\nFibonacci(%d) = %d\n", num, fibo);
			printf ("%5.1f seconds\n\n", difftime(end_time, start_time));
		}
	}
	return 0;
}

