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

int verify_user_data(int _age,double _height,double _weight,char _first_name[],char _last_name[],char _email[])
{
	if((_age>150)||(_age<18))
	{
		printf("User creation failed, invalid age range.\nAge must be between 18 and 150\n\n");
		return 0;
	}
	
	return 1;
}


User create_user(int _age,double _height,double _weight,char _first_name[],char _last_name[],char _email[])
{
	User _new_user;
	_new_user.valid=verify_user_data(_age,_height,_weight,_first_name,_last_name,_email);
	_new_user.age=_age;
	_new_user.height=_height;
	_new_user.weight=_weight;
	strcpy(_new_user.first_name,_first_name);
	strcpy(_new_user.last_name,_last_name);
	strcpy(_new_user.email,_email);

	return _new_user;
}

void show_user_info(User _user)
{

	printf("User info:\n");
	printf("Age: %d\n",_user.age);
	printf("Height: %lf\n",_user.height);
	printf("Weight: %lf\n",_user.weight);
	printf("First Name: %s\n",_user.first_name);
	printf("Last Name: %s\n",_user.last_name);
	printf("Email: %s\n",_user.email);

}

int main()
{

	User me;
	
	me=create_user(25,6.1,185,"Ivan","Shindev","shindev@mail.usf.edu");

	if(me.valid)
	{
		show_user_info(me);
	}
	else
	{
		printf("User is not valid\n");
		return -1;
	}	
	

	return 0;
}
