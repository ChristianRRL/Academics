#include <stdio.h>


int main()
{
	char new_url[140];
	char extracted[140];
	scanf("%s",&new_url);
	int i=0;
	int index2=0;
	int start_extraction=0;

	while(new_url[i]!='\0')
	{
		if(start_extraction==1)
		{
			extracted[index2]=new_url[i];
			index2++;
		}
		if(new_url[i]=='_')
		{
			start_extraction=1;
		}
		i++;
		
	}
	extracted[index2]='\0';
	printf("%s\n",extracted);
	return 0;
}
