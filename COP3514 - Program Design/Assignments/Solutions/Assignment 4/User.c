#include "User.h"
#include <stdio.h>
#include <string.h>

int verify_date(Date _date)
{
	if((_date.year<1900)||(_date.year>2013))
	{
		return 0;
	}
	if((_date.month<0)||(_date.month>12))
	{
		return 0;
	}
	if(_date.day<0)
	{
		return 0;
	}
	switch(_date.month)
	{
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			if(_date.day>31)
			{
				return 0;
			}
			break;
		case 4: case 6: case 9: case 11:
			if(_date.day>30)
			{
				return 0;
			}
			break;
		case 2:
			if(_date.day>28)
			{
				return 0;
			}
			break;		
	}
	return 1;
}

int verify_name(char _name[])
{
	
	int i=0;
	while(_name[i]!='\0')
	{
		if((_name[i]>='A')&&(_name[i]<='Z'))
		{
			_name[i]=_name[i]+('a'-'A');
		}
		if((_name[i]<'a')||(_name[i]>'z'))
		{
			return 0;
		}
		i++;
	}
	return 1;
}

int verify_username(char _username[])
{
	int i=0;
	while(_username[i]!='\0')
	{
		if(((_username[i]<'A')||(_username[i]>'Z'))&&((_username[i]<'a')||(_username[i]>'z'))&&((_username[i]<'0')||(_username[i]>'9')))
		{
			return 0;
		}
		i++;
	}
	return 1;
}

Date create_date(int year,int month,int day)
{
	Date _new_date;
	_new_date.year=year;
	_new_date.month=month;
	_new_date.day=day;
	return _new_date;
}

Message create_msg(User _sender,char _content[])
{
	Message _new_message;
	strcpy(_new_message.from,_sender.username);
	strcpy(_new_message.content,_content);
	return _new_message;
}

int verify_user_data(Date _date_of_birth,char _first_name[],char _last_name[],char _username[])
{
	int error=0;
	if(!verify_date(_date_of_birth))
	{
		printf("ERROR: Date of birth\n");
		error=1;
	}
	if(!verify_name(_first_name))
	{
		printf("ERROR: First name\n");
		error=1;
	}
	if(!verify_name(_last_name))
	{
		printf("ERROR: Last Name\n");
		error=1;
	}
	if(!verify_username(_username))
	{
		printf("ERROR: Username\n");
		error=1;
	}
	if(error)
		return 0;
	return 1;
}


User create_user(Date _date_of_birth,double _height,double _weight,char _first_name[],char _last_name[],char _username[],char _email[])
{
	User _new_user;
	_new_user.valid=verify_user_data(_date_of_birth,_first_name,_last_name,_username);
	_new_user.date_of_birth=_date_of_birth;
	_new_user.height=_height;
	_new_user.weight=_weight;
	strcpy(_new_user.first_name,_first_name);
	strcpy(_new_user.last_name,_last_name);
	strcpy(_new_user.username,_username);
	strcpy(_new_user.email,_email);
	strcpy(_new_user.message.content,"");
	strcpy(_new_user.message.from,"");
	return _new_user;
}

void show_user_info(User _user)
{

	if(_user.valid)
	{
		printf("\t\t\tUser info:\n");
		printf("\t\t\tDate of birth: %d/%d/%d\n",_user.date_of_birth.month,_user.date_of_birth.day,_user.date_of_birth.year);
		printf("\t\t\tHeight: %lf\n",_user.height);
		printf("\t\t\tWeight: %lf\n",_user.weight);
		printf("\t\t\tFirst Name: %s\n",_user.first_name);
		printf("\t\t\tLast Name: %s\n",_user.last_name);
		printf("\t\t\tUsername: %s\n",_user.username);
		printf("\t\t\tEmail: %s\n",_user.email);
	}
	else
	{
		printf("Invalid user\n");
	}

}

void send_message(int _sender_id,int _receiver_id,char _content[])
{
	users[_receiver_id].message=create_msg(users[_sender_id],_content);

}

void read_message(int _user_id)
{
	printf("\t\t\t%s\n",users[_user_id].message.content);
}

int verify_email(char _email[])
{
	char extracted[30];

	int i=0,i1=0;
	//extract what is before the '@'
	while(_email[i]!='\0')
	{
		if(_email[i]!='@')
		{
			extracted[i]=_email[i];
		}
		else
			break;
		i++;
	}
	extracted[i]='\0';
	//check if the username is correct
	if(verify_username(extracted)==0)
		return 0;

	//extract what is after the '@'
	while(_email[i]!='\0')
	{
		extracted[i1]=_email[i];
		i++;
		i1++;
	}
	extracted[i1]='\0';

	//check if the format is correct
	if(strcmp(extracted,"@mail.usf.edu")==0)
		return 1;
	else
		return 0;
}
