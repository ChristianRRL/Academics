//program(s): main.cpp & aRandomNumber.cpp & aRandomNumber.h
//author(s): Christian Rodriguez & Gabriel Sotolongo

#include <iostream>
#include <cstdlib>
#include <vector>
#include "aHistogram.h"
using namespace std;


aHistogram::aHistogram(void)
{
	this->setRange(1,9);
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

	binVector.resize(size);		//Errors (2) based on aHistogram.h

	return;
}

void aHistogram::update(int number)
{
	binVector.at(number)++;

	return;
}

int aHistogram::count(int randomNumber) const
{
	return binVector.at(randomNumber);
}

void aHistogram::display()
{
	index=0;
	int temp=0;
	double scale=0.0;
	for(int i=low;i<=high; ++i)
	{
		if(count(index) > temp)
		{
			temp=count(index);
		}
	}
	scale=10/(double)temp;

	index=0;
	for(int i=low; i<=high; ++i)
	{
		cout << (i+1) << ":  ";	
		for(int j=0; j<(count(index)*scale); ++j)
		{
			cout << "x";
		}
		cout << " " << "(" << count(index) << ")" << endl;
		++index;
	}

	cout << "The scale we are using is: " << scale;

	cout << endl;
	/*
	index=0;
	for(int i=low; i<=high; ++i)
	{
		cout << (i+1) << " ";
		for(int j=0; j<(binVector.at(index)/100); ++j)
		{
			cout << "x";
		}
		++index;
		cout << endl;
	}
	*/
	system("pause");
	return;
}

void aHistogram::clear()
{
	binVector.clear();	//Errors (2) based on aHistogram.h
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