#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	 
	FILE* fp;
	char string[100];
	fp=fopen("Myfile.txt","r");

	if(fp==NULL)
	{
		printf("File open error\n");
		return -1;
	}

	//scanf("%s",string);
	while(fscanf(fp,"%s",string)==1)
	{
		printf("%s\n",string);
	}
	
	fclose(fp);
	return 0;

}
