#include <stdio.h>


void find_sum(int x,int y,int *pS,int *pP)
{

	*pS=x+y;
	*pP=x*y;

}

int main()
{
	int x=10,y=20;
	int sum,product;
	int* pS=&sum;
	int* pP=&product;
	find_sum(x,y,pS,pP);

	return 0;
}
