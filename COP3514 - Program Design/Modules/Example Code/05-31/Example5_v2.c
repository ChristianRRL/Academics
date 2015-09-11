#include <stdio.h>

int main()
{
	char ch;
	int count=0;
	printf("Begin Loop!\n");
	while((ch=getchar())!='a')
	{
		if(ch==20)
		{
			count++;
		}
		printf("count=%d\nch=%d\n", count, ch);
	}

	return 0;
}

