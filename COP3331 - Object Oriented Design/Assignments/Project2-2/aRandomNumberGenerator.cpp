//program(s): main.cpp & aRandomNumber.cpp & aRandomNumber.h
//author(s): Christian Rodriguez & Gabriel Sotolongo

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include "aRandomNumberGenerator.h"
using namespace std;


aRandomNumberGenerator::aRandomNumberGenerator(void)
{
	this->setRange(1,9);
}


aRandomNumberGenerator::~aRandomNumberGenerator(void)
{
}

int aRandomNumberGenerator::generate()
{
	return (rand() % size ) + low; 
}

void aRandomNumberGenerator::setRange(int low, int high)
{
	int temp=0;
	if (low>high)
	{
		temp=low;
		low=high;
		high=temp;
	}

	this->low=low;
	this->high=high;
	size=(high - low) + 1;

	return;
}

/*
void aRandomNumberGenerator::aHistogram()
{
	vector<int> randomVec(size);
	int randomNumber=0;
	int index=0;

	for(int i=0; i<9000; ++i)
	{
		randomNumber=generate();
		index=randomNumber-low;
		randomVec.at(index)+=1;
	}

	index=0;
	for(int i=low; i<=high; ++i)
	{
		cout << (i) << " ----- " << randomVec.at(index) << endl;
		++index;
	}

	cout << endl;

	index=0;
	for(int i=low; i<=high; ++i)
	{
		cout << i << " ";
		for(int j=0; j<(randomVec.at(index)/100); ++j)
		{
			cout << "x";
		}
		++index;
		cout << endl;
	}

	system("pause");
	return;
}
*/

int aRandomNumberGenerator::getLowNumber() const
{
	return low;
}

int aRandomNumberGenerator::getHighNumber() const
{
	return high;
}

