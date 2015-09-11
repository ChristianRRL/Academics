#include "Warehouse13.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void createOffsetString(char **string,int size)
{
	*string=malloc((size+1)*sizeof(char));
	int i=0;
	while(i<size)
	{
		(*string)[i]=' ';
		i++;
	}
	(*string)[i]='\0';
}
int getNumberOfDigits(int number)
{
	int i=0;
	if(number==0)
		return 1;
	while(number!=0)
	{
		i++;
		number/=10;
	}
	return i;
}


int getMaxRowSize(Artifact artifact)
{
	char name[50];
	int r1=12+getNumberOfDigits(artifact.id);
	int r2=5+strlen(artifact.name);
	int r3=13+getNumberOfDigits(artifact.hazardLevel);
	int r4=7+getNumberOfDigits(artifact.active);
	if((r1>=r2)&&(r1>=r3)&&(r1>=r4))
		return r1;
	if((r2>=r1)&&(r2>=r3)&&(r2>=r4))
		return r2;
	if((r3>=r2)&&(r3>=r1)&&(r3>=r4))
		return r3;
	return r4;
	
}
void showWarehouse(Vault* vault)
{
	int max=3;   //How many vaults to show per line. Reduce this number if the format is not readable 
	while(vault!=NULL)
	{
		int i=0;
		Vault* temp=vault;
		while((i<max)&&(temp!=NULL))
		{
			int max=getMaxRowSize(*(temp->artifact));
			int r1=23;
			int dif=max-r1;
			char *string=NULL;
			createOffsetString(&string,dif);
			printf("Vault Address:%p%s--> ",temp,string);	
			temp=temp->nextVault;
			i++;
		}
		printf("\n");
		temp=vault;
		i=0;
		while((i<max)&&(temp!=NULL))
		{
			int max=getMaxRowSize(*(temp->artifact));
			int r1=26;
			int dif=max-r1;
			char *string=NULL;
			createOffsetString(&string,dif);
			printf("Artifact Address:%p%s--> ",temp->artifact,string);	
			temp=temp->nextVault;
			i++;
		}
		printf("\n");
		temp=vault;
		i=0;
		while((i<max)&&(temp!=NULL))
		{
			int max=getMaxRowSize(*(temp->artifact));
			int r1=12+getNumberOfDigits(temp->artifact->id);
			int dif=max-r1;
			char *string=NULL;
			createOffsetString(&string,dif);
			printf("Artifact id:%d%s--> ",temp->artifact->id,string);	
			temp=temp->nextVault;
			i++;
		}
		printf("\n");
		temp=vault;
		i=0;
		while((i<max)&&(temp!=NULL))
		{
			int max=getMaxRowSize(*(temp->artifact));
			int r2=5+strlen(temp->artifact->name);
			int dif=max-r2;
			char *string=NULL;
			createOffsetString(&string,dif);
			printf("Name:%s%s--> ",temp->artifact->name,string);
			temp=temp->nextVault;
			i++;		
		}
		printf("\n");
		temp=vault;
		i=0;
		while((i<max)&&(temp!=NULL))
		{
			int max=getMaxRowSize(*(temp->artifact));
			int r3=13+getNumberOfDigits(temp->artifact->hazardLevel);
			int dif=max-r3;
			char *string=NULL;
			createOffsetString(&string,dif);
			printf("Hazard Level:%d%s--> ",temp->artifact->hazardLevel,string);
			temp=temp->nextVault;
			i++;		
		}
		printf("\n");
		temp=vault;
		i=0;
		while((i<max)&&(temp!=NULL))
		{
			int max=getMaxRowSize(*(temp->artifact));
			int r4=7+getNumberOfDigits(temp->artifact->active);
			int dif=max-r4;
			char *string=NULL;
			createOffsetString(&string,dif);
			printf("Active:%d%s--> ",temp->artifact->active,string);
			temp=temp->nextVault;
			i++;		
		}
		printf("\n");
		i=0;
		while((i<max)&&(vault!=NULL))
		{
			vault=vault->nextVault;
			i++;		
		}
		printf("\n");
	}

}

int main()
{

	Vault *warehouse=NULL;
	Artifact *myArtifact=NULL;

//Create and store the first artifact
	if(createArtifact(&myArtifact,1,10,"Bruce Lee's Punching Bag"))
		printf("Artifact created\n\n");
	else
		printf("Artifact creation failed\n\n");

	if(storeArtifact(myArtifact,&warehouse))
		printf("Artifact stored\n\n");
	else
		printf("Artifact not stored\n\n");

	showArtifact(1,&warehouse);

//Create and store the second artifact
	if(createArtifact(&myArtifact,2,20,"Einstein-Grant Bridge Device"))
		printf("Artifact created\n\n");
	else
		printf("Artifact creation failed\n\n");

	if(storeArtifact(myArtifact,&warehouse))
		printf("Artifact stored\n\n");
	else
		printf("Artifact not stored\n\n");

	showArtifact(2,&warehouse);

//Create and store the third artifact
	if(createArtifact(&myArtifact,3,30,"Sodom and Gomorrah Salt Mask"))
		printf("Artifact created\n\n");
	else
		printf("Artifact creation failed\n\n");

	if(storeArtifact(myArtifact,&warehouse))
		printf("Artifact stored\n\n");
	else
		printf("Artifact not stored\n\n");

	showArtifact(3,&warehouse);

//Create and store the fourth artifact
	if(createArtifact(&myArtifact,4,20,"Thomas Edison's Bioelectric Stagecoach"))
		printf("Artifact created\n\n");
	else
		printf("Artifact creation failed\n\n");

	if(storeArtifact(myArtifact,&warehouse))
		printf("Artifact stored\n\n");
	else
		printf("Artifact not stored\n\n");

	showArtifact(4,&warehouse);

	if(activate(2,&warehouse))
		printf("Artifact activate\n\n");
	else
		printf("Artifact not found\n\n");
        
	showWarehouse(warehouse);
	printf("\n\n");

	if(neutralize(2,&warehouse))
		printf("Artifact neutralized\n\n");
	else
		printf("Artifact not neutralized\n\n");
	printf("\n\n");

	showWarehouse(warehouse);

	return 0;
}
