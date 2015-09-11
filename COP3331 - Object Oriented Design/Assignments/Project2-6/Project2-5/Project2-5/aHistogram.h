//file(s): aHistogram.cpp & aHistogram.h
//author(s): Christian Rodriguez & Gabriel Sotolongo

using namespace std;
#ifndef AHISTOGRAM_H
#define AHISTOGRAM_H

class aHistogram
{
public:
	aHistogram(void);								//constructor
	~aHistogram(void);							//destructor
	void setRange(int low, int high);			//set the range of the histogram
	void update(int number);					//update the bin in histogram
	int count(int randomNumber) const;	//count the bin in histogram
	void display();									//display histogram
	void clear();										//clear histogram
private:
	int index;											//global index for loops
	int low;												//low number
	int high;												//high number
	int size;												//size ((high - low) + 1)
	int number;										//number (aka bin) to be updated
	int randomNumber;							//number (aka bin) to be counted
	vector <int> binVector;						//global vector to store all bin numbers
};

#endif