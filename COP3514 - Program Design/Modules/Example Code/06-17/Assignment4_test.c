#include "User.h"
#include <stdio.h>
#include <string.h>

int main()
{

	
	Date date;
	char content[100]="Hello";
	char first_name[100]="Ivan";
	char last_name[100]="Shindev";
	char username[100]="ivan";
	char email[100]="shindev@mail.usf.edu";
	
	double height=6.1;
	double weight=185;
	date=create_date(2020,1,1);
	printf("%d %d %d\n",date.year,date.month,date.day);
	printf("verify date=%d\n",verify_date(date));

	printf("verify first name=%d\n",verify_name(first_name));

	User new_user=create_user(date,height,weight,first_name,last_name,username,email);
	return 0;
}
