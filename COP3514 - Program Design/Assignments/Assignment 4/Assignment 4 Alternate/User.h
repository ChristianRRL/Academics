#ifndef _UserH_
#define _UserH_

typedef struct 
{
	int year;
	int month;
	int day;
}Date;


typedef struct 
{
	char from[100];
	char content[100];
}Message;


typedef struct 
{
	Date date_of_birth;
	double height;
	double weight;
	char first_name[100];
	char last_name[100];
	char username[100];
	char email[100];
	Message message;
	int id;
	int valid;
}User;

User users[10];

int verify_date(Date _date);

int verify_name(char _name[]);

int verify_username(char _username[]);

int verify_user_data(Date _date_of_birth,char _first_name[],char _last_name[],char _username[], char _email[]);

int verify_email(char _email[]); //extra credit

Date create_date(int year,int month,int day);

Message create_msg(User _sender,char _content[]);

User create_user(Date _date_of_birth,double _height,double _weight,char _first_name[],char _last_name[],char _username[],char _email[]);

void show_user_info(User _user);

void send_message(int _sender_id,int _receiver_id,char _content[]);

void read_message(int _user_id);


#endif
