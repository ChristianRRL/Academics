/* This program prompts the user to setup a pin
   It handles invalid input properly 
*/


#include <stdio.h>
/* Complete the code for this program below */


int main()
{
	int pin,pin_verify,account;
	int done=-1;
	account=1;
	pin=1;
	int extra;
	char ch;
	while(done==-1)
	{
		printf("Please enter your 8 digit account number:\n");
		scanf("%d", &account);
		extra=0;
		while ((ch = getchar()) != '\n' && ch != EOF) /* flushing the input buffer */ 
		{
			extra++;
		}
		if((account<10000000)||(account>99999999)||(extra!=0))
		{
			printf("Invalid account number. Account number must be 8 digits.\n\n");
			account=1;
		}
		else
			done=1;
	}
	done=-1;
	while(done==-1)
	{
		printf("\nPlease choose a 4 digit pin number:\n");
		scanf("%d", &pin);
		extra=0;
		while ((ch = getchar()) != '\n' && ch != EOF) /* flushing the input buffer */ 
		{
			extra++;
		}
		if((pin<1000)||(pin>9999)||(extra!=0))
		{
			printf("Invalid pin number. Pin number must be 4 digits.\n\n");
			pin=1;
		}
		else
		{
			printf("Re-enter pin number:\n");
			scanf("%d", &pin_verify);
			extra=0;
			while ((ch = getchar()) != '\n' && ch != EOF) /* flushing the input buffer */ 
			{
				extra++;
			}
			if((pin_verify>1000)&&(pin_verify<9999)&&(extra==0)&&(pin==pin_verify))
			{
				printf("\nPin setup successful!\n");
				printf("Account #: %d\n",account);
				printf("Pin #: %d\n",pin);
				printf("Have a nice day.\n");
				done=1;
			}
			else
			{
				printf("Pin setup unsuccessful\n\n");
				pin=1;
			}
		}
	}

return 0;
}
