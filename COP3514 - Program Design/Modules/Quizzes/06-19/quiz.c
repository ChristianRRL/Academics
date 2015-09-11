#include <stdio.h>

typedef struct BOX
{
	int length;
	int width;
	int height;
	double weight;
	char contents[32];
} box_t;

void increment(box_t* pBox)
{
	pBox->length++;

}
int main()
{
	int dimension_total;
	box_t box1 = {24, 12, 12, 5.3, "Fine German Wine"};
	box_t *pBox; 
	pBox=&box1;
	
	printf("%d\n",(*pBox).length);

	increment(pBox); 

	printf("%d\n",box1.length);

	return 0;
}

