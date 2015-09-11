//program(s): main.cpp & aRandomNumber.cpp & aRandomNumber.h
//author(s): Christian Rodriguez & Gabriel Sotolongo

//#pragma once
#ifndef ARANDOMNUMBER_H
#define ARANDOMNUMBER_H

class aRandomNumber
{
public:
	aRandomNumber(void);
	~aRandomNumber(void);
	int generate();
	void setRange(int low, int high);
	//void aHistogram();
	int getLowNumber();
	int getHighNumber();
private:
	int low;
	int high;
	int size;
};

#endif