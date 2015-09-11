//file: main.cpp
//author(s): Christian Rodriguez & Gabriel Sotolongo

#include <iostream>
#include <cstdlib>
#include <vector>
#include "aHistogram.h"
#include "aCoin.h"
#include "aDie.h"
using namespace std;


int inputValidation(void);				//integer input validation function

int main()
{
	aCoin coinObject;					//a coin object
	aDie dieObject;						//a die object
	aHistogram coinHistogram;	//a coin histogram
	aHistogram dieHistogram;		//a die histogram
	int seed;								//seed for random number generator
	//int flips;									//number of flips
	//int rolls;									//number of rolls
	int index=0;							//index used in loops

	while(1)
	{
	cout << "Enter a valid seed. Enter a negative number to exit the program! ";
	seed=inputValidation();
	
	if(seed < 0)
	{
		break;
	}


	srand(seed);

	coinHistogram.setRange(coinObject.getLowNumber(), coinObject.getHighNumber());
	dieHistogram.setRange(dieObject.getLowNumber(), dieObject.getHighNumber());

	cout << "This coin will be flipped " << seed << " times." << endl;
	//cout << "How many times would you like to flip the coin? ";
	//flips=inputValidation();

	for (index=0; index<seed; ++index)
	{
		coinHistogram.update(coinObject.flip());
	}
	coinHistogram.display();
	coinHistogram.clear();

	cout << "This die will be rolled " << seed << " times." << endl;
	//cout << "How many times would you like to roll the die? ";
	//rolls=inputValidation();

	for (index=0; index<seed; ++index)
	{
		dieHistogram.update(dieObject.roll());
	}
	dieHistogram.display();
	dieHistogram.clear();
	}

	cout << "Thank you, come again!" << endl;;
	system("pause");

	return 0;
}

int inputValidation(void)				//integer input validation function
{
	int integer;
	int extra=0;
	char ch;
	while(1)
	{
		cin >> integer;

		while((ch=getchar()) != '\n' && ch != EOF)
		{
			extra++;
		}
		if(extra==0)
		{
			cout << endl;
			break;
		}
		else
		{
			cout << "Incorrect Input. Try Again: ";
		}
		extra=0;
		cin.clear();
	}

	return integer;
}
