#include "Assignment3.h"
#include <stdio.h>
#include <string.h>

// Complete the following functions

void init_url(char new_url[])
{
	/*
	This function sets the variable url to new_url and url_size to the number of characters in the url 
	It also initializes url_error_flag
	*/
	url_size = strlen(new_url);
	strncpy(url, new_url, sizeof(url_size-1));
	url_error_flag = 0;
}

void filter_url()
{
	/*
	This function filters the url and sets the value of the variable filtered_url
	*/
	int i;
	for (i = 0; url[i] != '?'; i++)
	{
		filter_url[i] = url[i];
	}
}

void extract_parameters()
{
	/*
	This function extracts the parameters from the url and stores them in the parameters array
	It also sets the value of number_of_parameters
	*/
}

void extract_values()
{
	/*
	This function extracts the values of the parameters from the url and stores them in the values array
	It also sets the value of number_of_values
	*/
}

void print()
{
	/*
	This function prints the filtered url and the parameters with their values
	*/
	printf("The URL is: %s\n", filtered_url);
	printf("\nThere are %d parameters and %d values.\n");
}
