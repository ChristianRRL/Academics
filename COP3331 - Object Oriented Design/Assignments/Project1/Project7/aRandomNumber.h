/*authors:
**Christian Rodriguez
**Gabriel Sotolongo
*/

#pragma once
#include <vector>
using namespace std;
class aRandomNumber
{
public:
	aRandomNumber(void);
	~aRandomNumber(void);
	void setRange(int low, int high);
	int generate(void);
private:
	int rangeMax;
	int rangeMin;
	int rangeSize;
	int randomNum;
	int index;
};

