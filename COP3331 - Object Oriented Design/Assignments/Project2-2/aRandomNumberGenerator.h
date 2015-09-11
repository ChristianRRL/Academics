//program(s): main.cpp & aRandomNumber.cpp & aRandomNumber.h
//author(s): Christian Rodriguez & Gabriel Sotolongo

//#pragma once
#ifndef ARANDOMNUMBER_H
#define ARANDOMNUMBER_H

class aRandomNumberGenerator
{
public:
	aRandomNumberGenerator(void);
	~aRandomNumberGenerator(void);
	int generate();
	void setRange(int low, int high);
	int getLowNumber() const;
	int getHighNumber() const;
private:
	int low;
	int high;
	int size;
};

#endif