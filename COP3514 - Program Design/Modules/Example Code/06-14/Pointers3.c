#include <stdio.h>

int main ()
{
	int value = 100;
	int *pValue;
	
	//pValue = &value;
	printf ("Before increment, value = %d\n", *pValue );
	
	*pValue += 1;
	printf ("After increment, value = %d\n", *pValue );
	return 0;
}

