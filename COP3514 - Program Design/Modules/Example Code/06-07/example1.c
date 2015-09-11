#include <stdio.h>
#define SIZE 3
double my_function(int x[],int size)
{

	double sum =0.0;
	double average = 0.0;

	int i = 0;
	for (i = 0; i < size; i++)
	{
		sum += x[i]; 
		x[i]=0;
	}
	average = sum / size;
	return average;

}


int main()
{


	int x=1;
	int return_par[3]={3,4,10};
	double average=my_function(return_par,3);
	printf("%d %d %d\n",return_par[0],return_par[1],return_par[2]);
	return 0;
}
