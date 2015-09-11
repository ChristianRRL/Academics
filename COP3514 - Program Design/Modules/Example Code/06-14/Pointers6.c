#include <stdio.h>


int main ()
{
	int array[8]={3,4,5,6,7,8,9,10};
	//int* array_of_pointers[8]; // An array of int pointers.
	
	int *pointer_to_array=array; // A pointer to an array of integers
	
	printf ("Before increment, value = %d\n", pointer_to_array[3] ); //the same as array[3]
	
	pointer_to_array[3] += 1;
	printf ("After increment, value = %d\n",pointer_to_array[3] );
	
	return 0;
}

