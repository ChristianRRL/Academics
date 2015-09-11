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
	int loopGate = 1;
	int extra;
	char ch;
	
	int acctNum;
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
			loopGate = 0;
		}
	}
	while (loopGate == 1);
	
	loopGate = 1;
	
	int acctPin;
	int acctPinVerify;
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
				loopGate = 0;
			}
			
			
		}
	}
	while (loopGate == 1);
	
	printf("\nPin setup successful!\n");
	printf("Account #: %d\n", acctNum);
	printf("Pin #: %d\n", acctPin);
	printf("Have a nice day.\n");
	
	return 0;
}