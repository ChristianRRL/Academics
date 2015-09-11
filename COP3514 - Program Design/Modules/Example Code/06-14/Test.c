#include <stdio.h>
#include <string.h>
int main()
{
	char _name[100];
	scanf("%s",&_name);
	int i=0;
	while(_name[i]!='\0')
	{
		if((_name[i]>='A')&&(_name[i]<='Z'))
			_name[i]=_name[i]+('a'-'A');
		i++;
	}


	char a='a';
	char z='z';
	char A='A';
	char Z='Z';
	char zero='0';
	char nine='9';
	printf("a=%d z=%d A=%d Z=%d zero=%d nine =%d %s\n",a,z,A,Z,zero,nine,name);
	return 0;
}
