#include "Assignment3.h"
#include <stdio.h>
#include <string.h>

// Complete the following functions

void init_url(char new_url[])
{
	/*
	This function sets the variable url to new_url and url_size to 
	the number of characters in the url 
	It also initializes url_error_flag
	*/
	strcpy(url,new_url);
	int i;
	for(i=0;url[i]!=NULL;i++)
	{
		url_size=i;
	}
	url_error_flag=0;
}

void filter_url()
{
	/*
	This function filters the url and sets the value of the 
	variable filtered_url
	*/
	int i;
	for(i=0;i<url_size;i++)
	{
		if(url[i]=='?')
			break;
	}
	strcpy(filtered_url,url);
	filtered_url[i]=NULL;
}

void extract_parameters()
{
	/*
	This function extracts the parameters from the url and stores 
	them in the parameters array
	It also sets the value of number_of_parameters
	*/
	int i;
	char temp[20];
	int temp_i=0;
	number_of_parameters=0;
	for(i=0;i<url_size;i++)
	{
		if((url[i]!='=')&&(i<url_size))
		{
			temp[temp_i]=url[i];
			temp_i++;
			i++;
		}
		temp[temp_i]=NULL;
		temp_i=0;
		if(strlen(temp)!=0)
		{
			strcpy(parameters[number_of_parameters],temp);
			number_of_parameters++;
		}
	}
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
}
