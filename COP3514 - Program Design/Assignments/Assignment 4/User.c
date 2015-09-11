#include "User.h"
#include <stdio.h>
#include <string.h>

int verify_date(Date _date)
{
	//Checks if the year is between 1900 and 2013 and if the month and day are correct.
	//January, March, May, July, August, October and December have 31 days
	//February has 28 days (do not check for leap year)
	//April, June, September and November have 30 days
	if (_date.year >= 1900 && _date.year <= 2013)
	{
		if (_date.month >= 1 && _date.month <= 12)
		{
			switch (_date.month)
			{
				case 1: case 3: case 5: case 7: case 8: case 10: case 12:
					if (_date.day >= 1 && _date.day <= 31)
						return 1;
					else
						return 0;
					break;
				case 4: case 6: case 9: case 11:
					if (_date.day >= 1 && _date.day <= 30)
						return 1;
					else
						return 0;
					break;
				case 2:
					if (_date.day >= 1 && _date.day <= 28)
						return 1;
					else
						return 0;
					break;
				default:
					return 0;
					break;
			}
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}
	
}

int verify_name(char _name[])
{
	//If the name has capital letters then change them to lower case letters
	//If the name has anything else besides letters then it is not valid
	int i = 0;
	while(_name[i] != '\0')
	{
		if((_name[i] >= 'A') && (_name[i] <= 'Z'))
		{
			_name[i] += ('a' - 'A');
		}
		if ((_name[i] < 'a') || (_name[i] > 'z'))
		{
			return 0;
		}
		i++;
	}
	return 1;
}

int verify_username(char _username[])
{
	//If the name has anything else besides letters and numbers then it is not valid
	int i = 0;
	while(_username[i] != '\0')
	{
		if ((_username[i] < '0') || (_username[i] > 'z'))
		{
			return 0;
		}
		else if (_username[i] >= ':' && _username[i] <= '@')
		{
			return 0;
		}
		else if (_username[i] >= '[' && _username[i] <= '`')
		{
			return 0;
		}
		i++;
	}
	return 1;
}

Date create_date(int year,int month,int day)
{
	//Create a date structure
	Date date;
	date.year = year;
	date.month = month;
	date.day = day;
	
	return date;
}

Message create_msg(User _sender,char _content[])
{
	//Create a message structure where "from" is the _sender username
	//and the content is _content
	Message message;
	message.from[100] = _sender.username;
	strcpy(message.content, _content);
	
	return message;
}

int verify_user_data(Date _date_of_birth,char _first_name[],char _last_name[],char _username[])
{
	//Verify the user data. You can use the other verification functions
	if (verify_date(_date_of_birth) == 0)
		printf("ERROR: Date of birth\n");
	if (verify_name(_first_name) == 0)
		printf("ERROR: First name\n");
	if (verify_name(_last_name) == 0)
		printf("ERROR: Last name\n");
	if (verify_username(_username) == 0)
		printf("ERROR: Username\n");
	if (verify_date(_date_of_birth) == 1 && verify_name(_first_name) == 1 && verify_name(_last_name) == 1 && verify_username(_username) == 1)
		return 1;
	else
		return 0;
}

User create_user(Date _date_of_birth,double _height,double _weight,char _first_name[],char _last_name[],char _username[],char _email[])
{
	//Create User structure
	User users;
	users.date_of_birth = _date_of_birth;
	users.height = _height;
	users.weight = _weight;
	strcpy(users.first_name, _first_name);
	strcpy(users.last_name, _last_name);
	strcpy(users.username, _username);
	strcpy(users.email, _email);
	//users.message.content;
	//users.from = _sender???
	users.id;
	users.valid;
	
	if(verify_user_data(_date_of_birth, _first_name, _last_name, _username) == 1)
		users.valid = 1;
	else
		users.valid = 0;

	return users;
}

void show_user_info(User _user)
{

	//Print the user info. Check the .pdf for format
	printf("\t\t\tUser info:\n");
	printf("\t\t\tDate of birth: %d/%d/%d\n", _user.date_of_birth.month, _user.date_of_birth.day, _user.date_of_birth.year);
	printf("\t\t\tHeight: %lf\n", _user.height);
	printf("\t\t\tWeight: %lf\n", _user.weight);
	printf("\t\t\tFirst Name: %s\n", _user.first_name);
	printf("\t\t\tLast Name: %s\n", _user.last_name);
	printf("\t\t\tUsername: %s\n", _user.username);
	printf("\t\t\tEmail: %s\n", _user.email);
}

void send_message(int _sender_id,int _receiver_id,char _content[])
{
	//Send a message from user id _sender to user id _receiver
	strcpy(users[_receiver_id].message.content,_content);
	strcpy(users[_receiver_id].message.from,users[_sender_id].username);

}

void read_message(int _user_id)
{
	//read the message stored in user id _user_id
	//printf("\t\t\t%s\n", _user_id.)
	printf("\t\t\t%s",users[_user_id].message.content);
}

/*
//EXTRA CREDIT ONLY
int verify_email(char _email[])
{
	int i = 0;
	char temp1[100];
	char temp2[100];
	int pos = 0;
	while (i!='\0' || i!='@')
	{
		temp1[i] = _email[i];
		i++
	}
	while (pos!='\0')
	{
		temp2[pos] = _email[i];
		pos++;
		i++;
	}
}

/*
void extract_parameters()
{
	int i=0;
	char temp[100];
	int pos=0;
	for(i=0; i!='\0'; i++)
	{
		if((_email[i]=='?')||(url[i]=='&'))
		{
			i++;
			while(_email[i]!='@')
			{
				temp[i]=url[i];
				pos++;
				i++;
			}
			temp[pos]='\0';
			pos=0;
			if(strlen(temp)!=0)
			{
				strcpy(parameters[number_of_parameters],temp);
				number_of_parameters++;
			}
		}
	}
}
*/