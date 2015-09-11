#include <stdio.h>

typedef struct 
{
	double x;
	double y;
} Point;


void mid_point(Point *p1,Point *p2,Point *p3)
{
	p3->x=(p1->x+p2->x)/2;
	p3->y=(p1->y+p2->y)/2;
}

int main()
{
	Point p1={0.0,0.0};
	Point p2={1.0,1.0};
	Point p3={0.0,0.0};
	
	mid_point(&p1,&p2,&p3);

	printf("Mid point %lf %lf \n",p3.x,p3.y);
	return 0;
}


