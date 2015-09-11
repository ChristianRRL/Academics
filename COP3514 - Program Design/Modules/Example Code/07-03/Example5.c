#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	 
	FILE *fp;
	char string[100];
	int number;
	fp=fopen("COP.txt","w");

	if(fp==NULL)
	{
		printf("File open error\n");
		return -1;
	}

	strcpy(string,"This is a string");
	number=10;
	fprintf(fp,"String is: %s \nNumber is: %d\n",string,number);
	fclose(fp);
	return 0;

}
