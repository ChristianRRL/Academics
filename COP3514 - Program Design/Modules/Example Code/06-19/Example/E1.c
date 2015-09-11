#include <stdio.h>

typedef struct BOX
{
	int length;
	int width;
	int height;
	double weight;
	char contents[32];
} box_t;


int main()
{
	int dimension_total;
	box_t box1 = {24, 12, 12, 5.3, "Fine German Wine"};
	box_t *pBox; //box_t *pBox=&box1;
	pBox=&box1;

	printf("%d\n",pBox-> length);
	printf("%d\n",box1.length);
	printf("%d\n",(*pBox).length);
	return 0;
}

