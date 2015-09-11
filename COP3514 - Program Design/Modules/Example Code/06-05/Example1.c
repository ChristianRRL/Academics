#include <stdio.h>
 
int my_function(int x) {
        printf("%d\n", x); 
        x = x + 1;
	if(x<10)
		my_function(x);
	return x;
}
 
int main() 
{
	int x=0;
	my_function(x);
        return 0;
}
