//file(s): aRandomNumberGenerator.cpp & aRandomNumberGenerator.h
//author(s): Christian Rodriguez & Gabriel Sotolongo

#include <iostream>
#include <cstdlib>
#include <vector>
#include "aRandomNumberGenerator.h"
using namespace std;


aRandomNumberGenerator::aRandomNumberGenerator(void)			//constructor
{
	this->setRange(getLowNumber(),getHighNumber());
}


aRandomNumberGenerator::~aRandomNumberGenerator(void)			//destructor
{
}

int aRandomNumberGenerator::generate(void) const				//random number generator
{
	return (rand() % size ) + low; 
}

void aRandomNumberGenerator::setRange(int low, int high)		//set the range of the random number generator
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

int aRandomNumberGenerator::getLowNumber(void) const			//get the low number
{
	return low;
}

int aRandomNumberGenerator::getHighNumber(void) const			//get the high number
{
	return high;
}

