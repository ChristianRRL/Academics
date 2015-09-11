/*
//	author: Christian Rodriguez
//	program: Assignment2.c
//
//	description:
//	This program prompts the user to setup a pin
//	It handles invalid input properly 
*/

#include <stdio.h>

int main()
{
	int acctNum;
	int acctPin;
	int acctPinVerify;
	int extra;
	char ch;
	
	//	Loop 1: Enter 8 digit numbers correctly
	do
	{
		printf("Please enter your 8 digit account number:\n");
		scanf("%d", &acctNum);
		extra = 0;
		
		while ((ch = getchar()) != '\n' && ch != EOF)	/*	flushing the input buffer */
		{
			extra++;
		}
		
		if (extra != 0 || (acctNum < 10000000 || acctNum > 99999999))
		{
			printf("Invalid account number. Account number must be 8 digits.\n\n");
		}
		else
		{
			break;
		}
	}
	while (1);
	
	//	Loop 2: Enter 4 digit pin correctly and verify by re-entering pin
	do
	{
		printf("\nPlease choose a 4 digit pin number:\n");
		scanf("%d", &acctPin);
		extra = 0;
		
		while ((ch = getchar()) != '\n' && ch != EOF)	/*	flushing the input buffer */
		{
			extra++;
		}
		
		if (extra != 0 || (acctPin < 1000 || acctPin > 9999))
		{
			printf("Invalid pin number. Pin number must be 4 digits.\n\n");
		}
		else
		{
			printf("Re-enter pin number:\n");
			scanf("%d", &acctPinVerify);
			extra = 0;
			
			while ((ch = getchar()) != '\n' && ch != EOF)		/* flushing the input buffer */
			{
				extra++;
			}
			
			if (extra != 0 || (acctPin != acctPinVerify))
			{
				printf("Pin setup unsuccessful\n\n");
			}
			else
			{
				break;
			}
		}
	}
	while (1);
	
	printf("\nPin setup successful!\n");
	printf("Account #: %d\n", acctNum);
	printf("Pin #: %d\n", acctPin);
	printf("Have a nice day.\n");
}