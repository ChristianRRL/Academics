#include "Assignment3.h"
#include <stdio.h>
#include <string.h>

void init_url(char new_url[])
{
	strcpy(url,new_url);
	int i=0;
	while(url[i]!='\0')
	{
		i++;
	}
	url_size=i;
	url_error_flag=0;
}

void filter_url()
{
	int i=0;
	for(i=0;i<url_size;i++)
	{
		if(url[i]=='?')
			break;
	}
	strcpy(filtered_url,url);	
	filtered_url[i]='\0';
	
}

void extract_parameters()
{
	int i=0;
	char temp[20];
	int pos=0;
	number_of_parameters=0;
	for(i=0;i<url_size;i++)
	{
		if((url[i]=='?')||(url[i]=='&'))
		{
			i++;
			while((url[i]!='=')&&(i<url_size))
			{
				temp[pos]=url[i];
				pos++;
				i++;
			}
			temp[pos]='\0';
			pos=0;
			if(strlen(temp)!=0)
			{
				strcpy(parameters[number_of_parameters],temp);
				number_of_parameters++;
			}
		}
	}
}

void extract_values()
{
	int i=0;
	char temp[20];
	int pos=0;
	number_of_values=0;
	int null_values=0;
	for(i=0;i<url_size;i++)
	{
		if(url[i]=='=')
		{
			if((url[i-1]=='&')||(url[i-1]=='?'))
			{
				url_error_flag=1;
				break;
			}
			i++;
			while((url[i]!='&')&&(i<url_size))
			{
				temp[pos]=url[i];
				pos++;
				i++;
			}
			temp[pos]='\0';
			pos=0;
			if(strlen(temp)==0)
			{
				null_values++;
			}
			strcpy(values[number_of_values],temp);
			number_of_values++;
		}
	}
	number_of_values-=null_values;
}

void print()
{

	printf("The URL is: %s\n\n",filtered_url);
	if(url_error_flag==1)
	{
		printf("URL ERROR\n");
	}
	else
	{
		printf("There are %d parameters and %d values.\n",number_of_parameters,number_of_values);
		int i;
		for(i=0;i<number_of_parameters;i++)
		{
			if(strlen(values[i])!=0)
				printf("Parameter %d: \"%s\" with value \"%s\"\n",i+1,parameters[i],values[i]);
			else
				printf("Parameter %d: \"%s\" with no value\n",i+1,parameters[i]);
		}	


	}
}
