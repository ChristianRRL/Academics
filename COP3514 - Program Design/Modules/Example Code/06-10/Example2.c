#include <stdio.h>
#include <string.h>

typedef struct 
{
	int age;
	double height;
	double weight;
	char first_name[100];
	char last_name[100];
	char email[100];
	int valid;
}User;

User create_user(int _age,double _height,double _weight,char _first_name[],char _last_name[],char _email[])
{
	User _new_user;
	_new_user.valid=0;
	/*data verification*/
	//Example
	if((_age>150)||(_age<18))
	{
		printf("User creation failed, invalid age range.\n Age must be between 18 and 150\n");
		return _new_user;
	}


	_new_user.age=_age;
	_new_user.height=_height;
	_new_user.weight=_weight;
	strcpy(_new_user.first_name,_first_name);
	strcpy(_new_user.last_name,_last_name);
	strcpy(_new_user.email,_email);
	_new_user.valid=1;
	
	return _new_user;
}


int main()
{

	User me;
	
	me=create_user(160,6.1,185,"Ivan","Shindev","shindev@mail.usf.edu");
	
	if(me.valid)
	{
		printf("User info:\n");
		printf("Age: %d\n",me.age);
		printf("Height: %lf\n",me.height);
		printf("Weight: %lf\n",me.weight);
		printf("First Name: %s\n",me.first_name);
		printf("Last Name: %s\n",me.last_name);
		printf("Email: %s\n",me.email);
	}
	else
	{
		printf("User is not valid\n");
		return -1;
	}	
	return 0;
}
