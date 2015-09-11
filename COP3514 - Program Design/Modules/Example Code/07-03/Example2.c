#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	 
	FILE *fp;
	char line[1];
	fp=fopen("Myfile.txt","r");

	if(fp==NULL)
	{
		printf("File open error\n");
		return -1;
	}

	int i=0;
	while(fgets(line,1,fp)!=NULL)
	{
		i++;
		printf("%s",line);
	}
	printf("while was executed %d times\n",i);
	fclose(fp);
	return 0;

}
