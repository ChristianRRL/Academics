/*
//	author: Christian Rodriguez
//	program: Assignment2.c
//
//	description:
//	This program prompts the user to setup a pin
//	It handles invalid input properly 
*/

#include <stdio.h>

/* Complete the code for this program below */

int main()
{
	int acctNum;
	int acctPin;
	int acctPinVerify;
	int loopGate = 1;
	int extra;
	char ch;
	
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
	
	/*
	printf("Please enter your 8 digit account number:\n");
	scanf("%d", &acctNum);
	while (loopGate == 0)	//	alternate: while(0) {... break; ...}
	{	
		if (acctNum >= 10000000 && acctNum <= 99999999)
		{
			loopGate = 1;
		}
		else
		{
			printf("Invalid account number. Account number must be 8 digits\n");
			printf("\nPlease enter your 8 digit account number:\n");
			scanf("%d", &acctNum);
		}
	}
	*/
	
	loopGate = 1;
	
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
	/*
	while (loopGate == 1)
	{
		printf("\nPlease choose a 4 digit number:\n");
		scanf("%d", &acctPin);
		while (loopGate == 0)
		{
			if (acctPin >= 1000 && acctPin <= 9999)
			{
				loopGate = 1;
			}
			else
			{
				printf("Invalid pin number. Pin number must be 4 digits.\n");
				printf("\n");
				printf("\nPlease choose a 4 digit pin number:\n");
				scanf("%d", &acctPin);
			}
		}
		
		loopGate = 0;
		
		printf("Re-enter pin number:\n");
		scanf("%d", &acctPinVerify);
		if (acctPin == acctPinVerify)
		{
			loopGate = 1;
		}
		else
		{
			printf("Pin setup unsuccessful\n");
			printf("\n");
		}
	}
	*/
	
	printf("\nPin setup successful!\n");
	printf("Account #: %d\n", acctNum);
	printf("Pin #: %d\n", acctPin);
	printf("Have a nice day.\n");
}