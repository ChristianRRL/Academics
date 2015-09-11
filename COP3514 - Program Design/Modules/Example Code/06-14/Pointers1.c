#include <stdio.h>

int main ()
{
	int value = 100;
	int *pValue;
	
	pValue = &value;
	printf ("Before increment, value = %d\n", value );
	
	*pValue += 1;//the same as value+=1;
	printf ("After increment, value = %d\n", value );
	return 0;
}

