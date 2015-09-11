#include <stdio.h>

int main()
{
	char ch;
	int count=0;
	while((ch=getchar())!='a')
	{
		if(ch==20)
		{
			count++;
		}
	}

	return 0;
}

