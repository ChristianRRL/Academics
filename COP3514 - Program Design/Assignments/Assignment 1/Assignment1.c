/*
//	author: Christian Rodriguez
//	program: Assignment1.c
//
//	description:
//	This program inputs four integer numbers a, b, c and d and
//	determines if the sum of the two largest numbers is the same
//	as the squared difference of the two smallest numbers
*/

#include <stdio.h>

/* Complete the code for this program below */


int main()
{
	int a, b, c, d;
	int return_value;
	int sum = 0, diffSqrd = 0;

	//	printf("Enter four integer numbers for a, b, c, and d");
	return_value = scanf("%d %d %d %d", &a, &b, &c, &d);

	if (a>=b && b>=c && c>=d && d>=a)		//	Row 0
	{
		sum = a+d;
		diffSqrd = (b-c)*(b-c);
	}
	else if (a>=b && b>=c && c>=d && d<=a)	//	Row 1
	{
		sum = a+b;
		diffSqrd = (c-d)*(c-d);
	}
	else if (a>=b && b>=c && c<=d && d>=a)	//	Row 2
	{
		sum = a+d;
		diffSqrd = (b-c)*(b-c);
	}
	else if (a>=b && b>=c && c<=d && d<=a)	//*	Row 3 *//
	{
		if (b>d)
		{
			sum = a+b;
			diffSqrd = (c-d)*(c-d);
		}
		else
		{
			sum = a+d;
			diffSqrd = (b-c)*(b-c);
		}
	}
	else if (a>=b && b<=c && c>=d && d>=a)	//	Row 4
	{
		sum = c+d;
		diffSqrd = (a-b)*(a-b);
	}
	else if (a>=b && b<=c && c>=d && d<=a)	//	Row 5
	{
		sum = a+c;
		diffSqrd = (b-d)*(b-d);
	}
	else if (a>=b && b<=c && c<=d && d>=a)	//*	Row 6 *//
	{
		if (a>c)
		{
			sum = a+d;
			diffSqrd = (b-c)*(b-c);
		}
		else
		{
			sum = c+d;
			diffSqrd = (a-b)*(a-b);
		}
	}
	else if (a>=b && b<=c && c<=d && d<=a)	//	Row 7
	{
		sum = a+c;
		diffSqrd = (b-d)*(b-d);
	}
	else if (a<=b && b>=c && c>=d && d>=a)	//	Row 8
	{
		sum = b+c;
		diffSqrd = (a-d)*(a-d);
	}
	else if (a<=b && b>=c && c>=d && d<=a)	//*	Row 9 *//
	{
		if (a>c)
		{
			sum = a+b;
			diffSqrd = (c-d)*(c-d);
		}
		else
		{
			sum = b+c;
			diffSqrd = (a-d)*(a-d);
		}
	}
	else if (a<=b && b>=c && c<=d && d>=a)	//	Row 10
	{
		sum = b+d;
		diffSqrd = (a-c)*(a-c);
	}
	else if (a<=b && b>=c && c<=d && d<=a)	//	Row 11
	{
		sum = a+b;
		diffSqrd = (c-d)*(c-d);
	}
	else if (a<=b && b<=c && c>=d && d>=a)	//*	Row 12 *//
	{
		if (b>d)
		{
			sum = b+c;
			diffSqrd = (a-d)*(a-d);
		}
		else
		{
			sum = c+d;
			diffSqrd = (a-b)*(a-b);
		}
	}
	else if (a<=b && b<=c && c>=d && d<=a)	//	Row 13
	{
		sum = b+c;
		diffSqrd = (a-d)*(a-d);
	}
	else if (a<=b && b<=c && c<=d && d>=a)	//	Row 14
	{
		sum = c+d;
		diffSqrd = (a-b)*(a-b);
	}
	else if (a<=b && b<=c && c<=d && d<=a)	//	Row 15
	{
		sum = b+c;
		diffSqrd = (a-d)*(a-d);
	}

	if (return_value != 4)
		printf("INVALID INPUT\n");
	else if (sum == diffSqrd)
		printf("%d equals %d\n", sum, diffSqrd);
	else if (sum != diffSqrd)
		printf("%d does not equal %d\n", sum, diffSqrd);
	else
		printf("INVALID INPUT\n");
}
