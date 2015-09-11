#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void filecopy(FILE *dest, FILE *source)
{
	char ch = fgetc(source);
	while( !feof(source))
	{
		fputc(ch,dest);
		ch = fgetc(source);
	}
}

void filecopy1(FILE *dest, FILE *source)
{
	int ch;
	while((ch = fgetc(source)) != EOF)
	{
		fputc(ch,dest);
	}
}

int main()
{
	 
	FILE *destination;
	FILE *source;
	destination=fopen("Destination.txt","w");
	source=fopen("Source.txt","r");
	
	filecopy(destination,source);
	
	fclose(destination);
	fclose(source);
	return 0;

}
