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
	
	printf("User info:\n");
	printf("Age: %d\n",me.age);
	printf("Height: %lf\n",me.height);
	printf("Weight: %lf\n",me.weight);
	printf("First Name: %s\n",me.first_name);
	printf("Last Name: %s\n",me.last_name);
	printf("Email: %s\n",me.email);
	return 0;
}
