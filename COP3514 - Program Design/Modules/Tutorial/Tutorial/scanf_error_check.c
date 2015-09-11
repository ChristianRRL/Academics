/* This program inputs 3 integer numbers and checks if the input is correct
*/

#include <stdio.h>


int main()
{
	int a,b;
	int return_val;
	printf("Please input 2 numbers:\n");
	return_val = scanf("%d %d", &a,&b);
	if(return_val!=2)
	{
		printf("INVALID INPUT\n");
	}
	else
	{
		printf("You entered %d and %d\n",a,b);
	}
	
return 0;
}
