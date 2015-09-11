#include "User.h"
#include <stdio.h>
#include <string.h>

int main()
{

	
	Date date;
	char content[100];
	char first_name[100];
	char last_name[100];
	char username[100];
	char email[100];
	
	double height;
	double weight;

	int i;
	int N=-1;
	int command,from,to,id;
	for(i=0;i<10;i++)
	{
		users[i].valid=0;
		strcpy(users[i].message.content,"EMPTY");
	}
	while((N<0)||(N>10))
	{
		printf("Enter number of users : ");
		scanf("%d",&N);
		printf("\n");
	}
	for(i=0;i<N;)
	{
		printf("************************Enter user info for [User ID=%d]************************** \n",i);
		printf("Date of birth mm/dd/yyyy: ");
		scanf("%d/%d/%d",&date.month,&date.day,&date.year);
		printf("\nFirst Name: ");
		scanf("%s",first_name);
		printf("\nLast Name: ");
		scanf("%s",last_name);
		printf("\nHeight: ");
		scanf("%lf",&height);
		printf("\nWeight: ");
		scanf("%lf",&weight);
		printf("\nUsername: ");
		scanf("%s",username);
		printf("\nEmail: ");
		scanf("%s",email);
		printf("\n");

		users[i]=create_user(date,height,weight,first_name,last_name,username,email);
		
		if(users[i].valid)
		{
			users[i].id=i;
			i++;
		}
		else
		{
			printf("Please correct the above errors\n");
		}
	}
	while(1)
	{
		printf("\n\n **************************Commands*******************************\n\n");
		printf("\t\t\t[1] View Users\n");
		printf("\t\t\t[2] Compose Message\n");
		printf("\t\t\t[3] Read Message\n");
		printf("\t\t\t[4] User information\n");
		printf("\t\t\t[5] Exit\n");
		printf("\n\n *****************************************************************\n\n");
		scanf("%d",&command);
		if(command==5)
			break;
		if(command==1)
		{
			for(i=0;i<N;i++)
			{
				printf("\t\t\tUsername: \"%s\" \t\tUser Id: \"%d\"\n",users[i].username,i);
			}
		}
		if(command==2)
		{
			printf("\n *****************************************************************\n");
			printf("\t\t\tFrom [User Id]: ");
			scanf("%d",&from);
			printf("\n *****************************************************************\n");
			printf("\n\t\t\tTo [User Id]: ");
			scanf("%d",&to);
			printf("\n *****************************************************************\n");
			printf("\n\t\t\tContent: ");
			gets(content);
			gets(content);
			send_message(from,to,content);
			printf("\n *****************************************************************\n");
		}
		if(command==3)
		{
			printf("\n\t\t\tEnter [User Id]: ");
			scanf("%d",&id);
			printf("\t\t\tMessage:\n");
			printf("\n *****************************************************************\n");
			read_message(id);
			printf("\n *****************************************************************\n");
		}
		if(command==4)
		{
			printf("\n\t\t\t Enter [User Id]: ");
			scanf("%d",&id);
			show_user_info(users[id]);
			printf("\n *****************************************************************\n");
			printf("\n *****************************************************************\n");
		}
	}
	

	return 0;
}
