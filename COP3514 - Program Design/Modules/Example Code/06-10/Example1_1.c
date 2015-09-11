#include <stdio.h>

typedef struct 
{
	int year;
	int month;
	int day;
	//int hours;
	//int minutes;
	//int seconds;
}Date;

typedef struct 
{
	Date date_of_birth;
	double height;
	double weight;
	char first_name[100];
	char last_name[100];
	char email[100];
}User;


int main()
{
	Date my_birthday={1987,1,1}; //<--- not my real birthday 
	User me={my_birthday,6.1,185,"Ivan","Shindev","shindev@mail.usf.edu"};
	printf("%d/%d/%d\n",me.date_of_birth.month,me.date_of_birth.day,me.date_of_birth.year);
	return 0;
}
