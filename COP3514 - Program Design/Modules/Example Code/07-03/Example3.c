#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	 
	FILE *fp;
	fp=fopen("MyfileWrite.txt","a");

	if(fp==NULL)
	{
		printf("File open error\n");
		return -1;
	}

	fputs("This is the first line\n",fp);
	fputs("This is something else\n",fp);

	fclose(fp);
	return 0;

}
