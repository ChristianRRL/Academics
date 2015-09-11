#include <stdio.h>
int ValidateInput()
{
	int number;
	int extra;
	char ch;
	while(1)
	{
		scanf("%d", &number);
		extra=0;
		while ((ch = getchar()) != '\n') /* flushing the input buffer */
		{
			extra++;
		}
		if(extra!=0)
		{
			printf("Invalid input\n");
		}
		else
		{
			return number;
		}
	}
}

void Input(int array[],int size)
{
	int i;
	for(i=0;i<size;i++)
	{
		array[i]=ValidateInput();
	}
}

void sort_array(int array[],int N)
{
	int i,j,temp;
	for(i=0;i<N-1;i++)
	{
		for(j=i+1;j<N;j++)
		{
			if(array[i]<array[j])
			{
				temp=array[i];
				array[i]=array[j];
				array[j]=temp;
			}
		}
	}
}

void printf_array(int array[],int N)
{
	int i;	
	printf("\n****************************************\n");
	for(i=0;i<N;i++)
	{
		printf("%d\n",array[i]);
	}
}

int main()
{
	int N=-1;
	int array[1000];
	int i,j,temp;
	while((N<0)||(N>1000))
	{
		printf("Please enter N\n");
		N=ValidateInput();
	}
	Input(array,N);
	sort_array(array,N);
	printf_array(array,N);

return 0;
}

