#include <stdio.h>

typedef struct 
{
	int age;
	double height;
	double weight;
	char first_name[100];
	char last_name[100];
	char email[100];
}User;


int main()
{

	User me={25,6.1,185,"Ivan","Shindev","shindev@mail.usf.edu"};
	
	me.age=18;
	printf("Age: %d\n",me.age);
	return 0;
}
