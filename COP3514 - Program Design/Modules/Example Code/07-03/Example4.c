#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	 
	FILE *fp;
	char string[100];
	int number;
	fp=fopen("Myfile1.txt","r");

	if(fp==NULL)
	{
		printf("File open error\n");
		return -1;
	}

	while(fscanf(fp,"%s %d\n",string,&number)==2)
	{
		printf("%s %d\n",string,number);
	}
	fclose(fp);
	return 0;

}
