#include <stdio.h>

int main()
{
	int x,y;
	printf ("Please enter integers x, y\n");

	scanf("%d %d",&x,&y);
	
	
	if (x!=y)
	{
		printf ("\nx and y are different\n");
	}
	else
	{
		printf ("\nx==y\n");
	}
return 0;
}

