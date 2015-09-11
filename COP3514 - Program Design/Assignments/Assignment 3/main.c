/* URL filter
*/
#include "Assignment3.h"
#include <stdio.h>

/*
You may use this main file to test the functionality of your program.
Input cases from the Assignment3.pdf examples:

Input1: http://example.com/shop/index.php?product_id=58&highlight=blue+shoes&cat_id=5&sessionid=123&affid=543

Input2: http://example.com/shop/index.php?product_id=&highlight=blue+shoes&cat_id=&sessionid=123&affid=543

Input3: http://example.com/shop/index.php

Input4: http://facebook.com/index.php?name=John&last_name=Smith

Input5: http://facebook.com/index.php?name=John&=Smith

Input6: http://example.com/shop/index.php?=58&highlight=blue+shoes&=5&sessionid=123&affid=543

*/

int main()
{
	
	char new_url[140];
	scanf("%s",&new_url);
	init_url(new_url);
	filter_url();
	extract_parameters();
	extract_values();
	print();
return 0;
}
