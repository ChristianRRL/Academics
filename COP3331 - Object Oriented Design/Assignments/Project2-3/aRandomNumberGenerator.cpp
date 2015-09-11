//program(s): main.cpp & aRandomNumber.cpp & aRandomNumber.h
//author(s): Christian Rodriguez & Gabriel Sotolongo

#include <iostream>
#include <cstdlib>
#include <vector>
#include "aRandomNumberGenerator.h"
using namespace std;


aRandomNumberGenerator::aRandomNumberGenerator(void)
{
	this->setRange(getLowNumber(),getHighNumber());
}


aRandomNumberGenerator::~aRandomNumberGenerator(void)
{
}

int aRandomNumberGenerator::generate(void)
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

int aRandomNumberGenerator::getLowNumber(void) const
{
	return low;
}

int aRandomNumberGenerator::getHighNumber(void) const
{
	return high;
}

