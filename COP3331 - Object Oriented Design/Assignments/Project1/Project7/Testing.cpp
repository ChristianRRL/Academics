#include <iostream>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

int main()
{
	int rangeMin = 1;
	int rangeMax = 9;
	int index = 0;
	int randomNum = 1;
	srand(time(0));	

	cout << "Enter the Range Min: " << endl;
	cin >> rangeMin;
	cout << "Enter the Range Max: " << endl;
	cin >> rangeMax;

	int rangeSize = rangeMax - rangeMin;

	
	vector<int> randomVec(rangeSize);				//creating vector based on the 'rangeSize'

	for (int i = 0; i<9000; ++i)						//loop generates 9000 random numbers
	{
		randomNum = ((rand() % rangeMax) + rangeMin);	//setting variable 'randNum' to a random number between 'rangeMin' and 'rangeMax'
		index = randomNum - rangeMin;					//setting the appropriate index for the random number generated
		//randomVec.at(index) += 1;						//increasing the value at index by 1
		cout << randomNum << endl;
	}

}