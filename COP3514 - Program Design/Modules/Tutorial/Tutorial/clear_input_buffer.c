/* This program prompts the user for an integer input. 
   If an invalid input is inputed the input buffer is flushed
*/


#include <stdio.h>
int main()
{
	int number;
	int extra;
	char ch;
	printf("Please enter a number:\n");
	scanf("%d", &number);
	extra=0;
	while ((ch = getchar()) != '\n' && ch != EOF) /* flushing the input buffer */ 
	{
		extra++;
	}
	if(extra!=0)
	{
		printf("Invalid input\n");
	}
	else
	{
		printf("You have entered %d\n",number);
	}
return 0;
}
