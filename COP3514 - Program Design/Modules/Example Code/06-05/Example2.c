#include <time.h>
#include <stdio.h>

int Fibonacci (int n)
{
	int pred1 = 1;
	int pred2 = 1;
	int i, next;
	if (n <= 2)
	{
		return 1;
	}
	for (i = 3; i <= n; i++)
	{
		next = pred1 + pred2;
		pred2 = pred1;
		pred1 = next;
	}
	return next;
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

