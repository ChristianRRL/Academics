#include <stdio.h>

void find_middle_point(double A1[],double A2[],double middle[])
{
	
	middle[0]=(A1[0]+A2[0])/2;
	middle[1]=(A1[1]+A2[1])/2;
	A1[0]=0;
	A2[0]=0;
}


int main()
{


	double P1[2]={1.0,1.0};
	double P2[2]={2.0,2.0};
	double middle_point[2];

	find_middle_point(P1,P2,middle_point);

	printf("%lf %lf %lf %lf\n",P1[0],P1[1],P2[0],P2[1]);
	return 0;
}
