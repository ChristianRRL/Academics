//program(s): main.cpp & aRandomNumber.cpp & aRandomNumber.h
//author(s): Christian Rodriguez & Gabriel Sotolongo

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
//#include "aRandomNumberGenerator.h"
#include "aHistogram.h"
#include "aCoin.h"
#include "aDie.h"
using namespace std;


aHistogram::aHistogram(void)
{
}


aHistogram::~aHistogram(void)
{
}

void aHistogram::setRange(int low, int high)
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

	vector<int> randomVec(size);

	return;
}


void aHistogram::update(int number)
{

}

void aHistogram::display()
{
	vector<int> randomVec(size);
	int randomNumber=0;
	int index=0;
	for(int i=getLowNumber(); i<=getHighNumber(); ++i)
	{
		cout << (i) << " ----- " << randomVec.at(index) << endl;
		++index;
	}

	cout << endl;

	index=0;
	for(int i=getLowNumber(); i<=getHighNumber(); ++i)
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

void aHistogram::clear()
{
	randomNumber=0;
	number=0;
	//clear range
}


int aHistogram::count(int randomNumber) const
{
	
}


/*
int aHistogram::count(int randomNumber)
{
	if(randomNumber > 10000 || randomNumber < -10000)
		return randomNumber / 1000;
	else if((randomNumber > 1000 && randomNumber < 10000) || (randomNumber < -1000 && randomNumber > -10000))
		return randomNumber / 100;
	else if((randomNumber > 100 && randomNumber < 1000) || (randomNumber < -100 && randomNumber > -1000))
		return randomNumber / 10;
	else
		return randomNumber;
}
*/