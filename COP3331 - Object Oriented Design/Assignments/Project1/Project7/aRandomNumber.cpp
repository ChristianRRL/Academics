/*authors:
**Christian Rodriguez
**Gabriel Sotolongo
*/

#include "aRandomNumber.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

aRandomNumber::aRandomNumber(void)
{
}


aRandomNumber::~aRandomNumber(void)
{
}


void aRandomNumber::setRange(int low, int high)
{
	rangeMin = low;								//setting input integer 'low' to rangeMin
	rangeMax = high;							//setting input integer 'high' to rangeMax
	int temp = 0;								//creating temp variable and setting to 0

	if (rangeMin > rangeMax)					//if 'rangeMin' is greater than 'rangeMax' reverse the values
	{
		temp = rangeMin;
		rangeMin = rangeMax;
		rangeMax = temp;
	}

	rangeSize = (rangeMax - rangeMin) + 1;		//setting the difference between 'rangeMax' and 'rangeMin' to 'rangeSize'
}

int aRandomNumber::generate(void)
{
	srand(time(0));	
	
	vector<int> randomVec(rangeSize);				//creating vector based on the 'rangeSize'
	index = 0;
	randomNum = 0;

	for (int i = 0; i<9000; ++i)						//loop generates 9000 random numbers
	{
		randomNum = ((rand() % rangeMax) + rangeMin);	//setting variable 'randNum' to a random number between 'rangeMin' and 'rangeMax'
		index = randomNum - rangeMin;					//setting the appropriate index for the random number generated
		randomVec.at(index) += 1;						//increasing the value at index by 1
	}
	
	index = 0;
	for (int i = rangeMin; i<=rangeMax; ++i)
	{
		cout << (i) << " ----- " << randomVec.at(index) << endl;
		++index;
	}

	cout << endl;

	index = 0;
	for (int i = rangeMin; i <= rangeMax; ++i)
	{
		
		cout << i << " ";
		for (int j = 0; j < (randomVec.at(index) / 100); ++j)
		{
			cout << "x";
		}
		++index;
		cout << endl;
	}

	system("pause");

	return 0;

}
