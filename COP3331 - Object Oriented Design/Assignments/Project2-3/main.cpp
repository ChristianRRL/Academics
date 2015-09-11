//program(s): main.cpp & aRandomNumber.cpp & aRandomNumber.h
//author(s): Christian Rodriguez & Gabriel Sotolongo

#include <iostream>
#include <cstdlib>
#include <vector>
#include <limits>
#include <string>
#include <ios>
//#include "aRandomNumberGenerator.h"
#include "aHistogram.h"
#include "aCoin.h"
#include "aDie.h"
using namespace std;


int main()
{
	aCoin coinObject;
	aDie dieObject;
	aHistogram coinHistogram;
	aHistogram dieHistogram;
	int flips;
	int rolls;
	string heads;
	string tails;
	int index=0;
	int number=0;
	int seed = 0;
	int extra=0;
	char ch;

	while(1)
	{
		cout << "Enter a valid seed: ";
		cin >> seed;

		while((ch=getchar()) != '\n' && ch != EOF)
		{
			extra++;
		}
		if(extra==0)
		{
			break;
		}
		else
		{
			cout << "Incorrect Input. Try Again." << endl;
		}
		extra=0;
		cin.clear();
	}


	/*
	cout << "Enter a valid seed: ";
	while(!(cin>>seed))
	{
		cout << "Enter a valid seed: ";
		string garbage;
		cin.clear();
		getline(cin,garbage);
	}


	/*
	cout << "Please enter a number: " << endl;
	while (!(cin>>seed))
	{
		cin.clear();
		cin.ignore(numberic_limits<streamsize>::max());
		cout << "Incorrect, try again" << endl;
	}


	/*
	while(!(cin >> seed))
	{
		cin.clear();
		seed=0;
		cout << "Invalid Input. Try again." << endl;
	}


	/*
	while(1)
	{
		cout << "Enter a valid seed value: ";
		cin >> *seed;

		if(seed)
		{
			break;
		}
		else
		{
			cout << "Incorrect Input. Try again." << endl;
		}
		delete &seed;
	}
	*/

	srand(seed);

	coinHistogram.setRange(coinObject.getLowNumber(), coinObject.getHighNumber());
	dieHistogram.setRange(dieObject.getLowNumber(), dieObject.getHighNumber());

	extra=0;
	while(1)
	{
		cout << "How many times would you like to flip the coin? ";
		cin >> flips;

		while((ch=getchar()) != '\n' && ch != EOF)
		{
			extra++;
		}
		if(extra==0)
		{
			break;
		}
		else
		{
			cout << "Incorrect Input. Try Again." << endl;
		}
		extra=0;
		cin.clear();
	}

	for (index=0; index<flips; ++index)
	{
		coinHistogram.update(coinObject.flip());
	}
	coinHistogram.display();
	coinHistogram.clear();

	extra=0;
	while(1)
	{
		cout << "How many times would you like to roll the die? ";
		cin >> rolls;

		while((ch=getchar()) != '\n' && ch != EOF)
		{
			extra++;
		}
		if(extra==0)
		{
			break;
		}
		else
		{
			cout << "Incorrect Input. Try Again." << endl;
		}
		extra=0;
		cin.clear();
	}

	for (index=0; index<rolls; ++index)
	{
		dieHistogram.update(dieObject.roll());
	}
	dieHistogram.display();
	dieHistogram.clear();
}


/*
	while(1)
	{
		cout << "Enter an integer to seed the random number generator: ";
		cin >> seed;

		while((ch=getchar()) != '\n' && ch != EOF)
		{
			extra++;
		}
		if (extra==0)
		{
			break;
		}
		else
		{
			cout << "Invalid Input!" << endl;
		}
		extra=0;
	}
*/

/*
int main()
{
	srand(time(NULL));


	aRandomNumber numberObject1;
	aRandomNumber numberObject2;
	aRandomNumber numberObject3;


	int x=0;
	int y=0;

	cout << "Enter a low number: ";
	cin >> x;
	cout << "Enter a high number: ";
	cin >> y;

	numberObject2.setRange(5,15);
	numberObject3.setRange(x,y);

	cout << "The first set of randomly generated numbers is: " << endl;
	numberObject1.aHistogram();
	cout << "The second set of randomly generated numbers is: " << endl;
	numberObject2.aHistogram();
	cout << "The third set of randomly generated numbers is: " << endl;
	numberObject3.aHistogram();


	system("pause");
	return 0;
}
*/