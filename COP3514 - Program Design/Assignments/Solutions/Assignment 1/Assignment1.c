/* This program inputs four integer numbers a, b, c and d and 
   determines if the sum of the two largest numbers is the same 
   as the squared difference of the two smallest numbers
*/

#include <stdio.h>

/* Complete the code for this program below */


int main()
{
	int a,b,c,d;
	int return_val; //variable to help us determine if the input was an integer
	int temp; //temporal variable to help us switch values
	return_val = scanf("%d %d %d %d", &a,&b,&c,&d);
	if(return_val!=4)
	{
		printf("INVALID INPUT\n");
		return -1;
	}
	
	/*since we only have 4 variables we can sort them just by using "if" functions*/

	// put the largest value in the variable "a" by comparing it with the rest of the variables
	if(b>a)
	{
		temp=a;
		a=b;
		b=temp;		
	}
	if(c>a)
	{
		temp=a;
		a=c;
		c=temp;		
	}
	if(d>a)
	{
		temp=a;
		a=d;
		d=temp;		
	}
	
	// put the second to largest value in the variable "b" by comparing it with "c" and "d"
	if(c>b)
	{
		temp=b;
		b=c;
		c=temp;		
	}
	if(d>b)
	{
		temp=b;
		b=d;
		d=temp;		
	}

	// put the third to largest value in the variable "c" by comparing it with "d"
	if(d>c)
	{
		temp=c;
		c=d;
		d=temp;		
	}

	if((a+b)==((c-d)*(c-d)))
		printf("%d equals %d\n",(a+b),((c-d)*(c-d)));
	else
		printf("%d does not equal %d\n",(a+b),((c-d)*(c-d)));
return 0;
}
