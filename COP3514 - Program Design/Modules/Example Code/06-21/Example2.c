#include <stdio.h>

typedef struct
{
	char from[20];
	char content[100];

}Message;

typedef struct
{
	char name[30];
	Message message;
}User;


void change_msg_content(User *pUser)
{

	strcpy(pUser->message.content,"Changed");

}

int main()
{

	User new_user;
	User *pUser=&new_user;
	strcpy(new_user.message.content,"Hello");
	change_msg_content(pUser);
	printf("%s\n",new_user.message.content);
	return 0;
}
