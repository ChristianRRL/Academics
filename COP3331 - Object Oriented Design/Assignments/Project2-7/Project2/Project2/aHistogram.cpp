//file(s): aHistogram.cpp & aHistogram.h
//author(s): Christian Rodriguez & Gabriel Sotolongo

#include <iostream>
#include <cstdlib>
#include <vector>
#include "aHistogram.h"
using namespace std;


aHistogram::aHistogram(void)								//constructor
{
	this->setRange(1,9);
}


aHistogram::~aHistogram(void)								//destructor
{
}

void aHistogram::setRange(int low, int high)				//set the range of the histogram
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

	binVector.resize(size);

	return;
}

void aHistogram::update(int number)							//update the bin in histogram
{
	binVector.at(number)++;

	return;
}

int aHistogram::count(int randomNumber) const				//count the bin in histogram
{
	return binVector.at(randomNumber);
}

void aHistogram::display()									//display histogram
{
	int temp=0;
	double scale=0.0;
	for(int i=low; i<=high; i++)
	{
		if(count(i) > temp)
		{
			temp=count(i);
		}
	}

	scale=10/(double)temp;

	for(int i=low; i<=high; i++)
	{
		if((high - low) == 1)
		{
			if(i == low)
			{
				cout << "Heads:  ";
			}
			if(i == high)
			{
				cout << "Tails:  ";
			}
		}
		else
		{
			cout << (i+1) << ":  ";
		}

		for(int j=0; j<count(i)*scale; j++)
		{
			cout << "x";
		}
		cout << " " << "(" << count(i) << ")" << endl;
	}

	cout << "The scale we are using is: " << scale << endl;

	system("pause");
	cout << endl;
	return;
}

void aHistogram::clear()										//clear histogram
{
	binVector.clear();
}
