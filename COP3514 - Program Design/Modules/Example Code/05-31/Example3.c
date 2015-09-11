#include <stdio.h>


int main()
{
	int N;
	printf("please enter N\n");
	scanf("%d",&N);
	switch(N)
	{
		case 1: case 2: case 3: case 4: case 5:
			printf("N is less then 6\n");
			break;
		case 6: case 7: case 8: case 9: case 10: 
			printf("N is less than 11 and bigger than 5\n");
			break;
		default:
			printf("N is undefined\n");
	
	}
	return 0;
}
