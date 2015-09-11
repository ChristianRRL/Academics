#include "Warehouse13.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*For all functions if a malloc returns NULL "Error allocating memory" should be printed. Return 0 if the malloc returns NULL*/
/*
pArtifact is a pointer to an address of a pointer that points to an Artifact structure
Allocate memory for that structure and set the id, hazardLevel, name and active parameters 
to the values of the parameters provided to the function
Set the active parameter to 0
Return 1 memory was allocated, otherwise return 0
*/
int createArtifact(Artifact** pArtifact,int _id,int _hazardLevel,char _name[])
{
	(* pArtifact)=malloc (sizeof(Artifact));

	if((* pArtifact)==NULL)
	{
		printf("Error allocating memory\n");
		return 0;
	}
	
	(* pArtifact)->name=malloc ((strlen(_name)+1)*sizeof(char));

	if((* pArtifact)->name==NULL)
	{
		printf("Error allocating memory\n");
		return 0;
	}
	strcpy((* pArtifact)->name,_name);
	(* pArtifact)->id=_id;
	(* pArtifact)->active=0;
	(* pArtifact)->hazardLevel=_hazardLevel;
	return 1;
}

/*
pArtifact is a pointer a Artifact structure
pVault is a pointer to an address of a pointer that points to the first Vault variable (the warehouse)
Find the first NULL Vault in the warehouse and allocate memory for it
Set the artifact pointer in the new Vault to pArtifact
Return 1 memory was allocated, otherwise return 0
*/
int storeArtifact(Artifact* pArtifact,Vault** pVault)
{
	if((*pVault)==NULL)
	{
		(*pVault)=malloc (sizeof(Vault));
		if((*pVault)==NULL)
		{
			printf("Error allocating memory\n");
			return 0;
		}
		else
		{
			(*pVault)->artifact=pArtifact;
			return 1;
		}
	}
	else
		return storeArtifact(pArtifact,&((*pVault)->nextVault));

}

/*
_id is the id of the artifact to be activated
pVault is a pointer to an address of a pointer that points to the first Vault variable (the warehouse)
Go through the Vault structures in the warehouse and find the artifact with the same id as _id and 
set the active parameter to 1. 
Return 1 only if an artifact with id the same as _id exsists, otherwise return 0
*/
int activate(int _id,Vault** pVault)
{
	if((*pVault)!=NULL)
	{
		if((*pVault)->artifact!=NULL)
		{
			if((*pVault)->artifact->id==_id)
			{
				(*pVault)->artifact->active=1;
				return 1;
			}
			else
			{
				return  activate(_id,&((* pVault)->nextVault));
			}

		}
	}
	return 0;
	
}

/*
_id is the id of the artifact to be activated
pVault is a pointer to an address of a pointer that points to the first Vault variable (the warehouse)
Go through the Vault structures in the warehouse and find the artifact with the same id as _id
If the active parameter is 1 then free the memory of that artifact and free the memory of the Vault 
Make sure you connect the previous Vault and the next Vault 
Return 1 only if an artifact with id the same as _id exsists, otherwise return 0
*/
int neutralize(int _id,Vault** pVault)
{
	if((*pVault)!=NULL)
	{
		if(((*pVault)->artifact->id==_id)&&((*pVault)->artifact->active==1))
		{
			Vault*	temp1=(*pVault);
			(*pVault)=(*pVault)->nextVault;
			free(temp1->artifact);
			temp1->artifact=NULL;

			free(temp1);
			temp1=NULL;
			return 1;
		}
		else
		{
			
			Vault*	temp1=(*pVault);
			Vault* temp2=temp1;
			while(temp1!=NULL)
			{
					if((temp1->artifact->id==_id)&&(temp1->artifact->active==1))
					{
						temp2->nextVault=temp1->nextVault;
						free(temp1->artifact);
						temp1->artifact=NULL;

						free(temp1);
						temp1=NULL;
						return 1;
					}
					temp2=temp1;
					temp1=temp1->nextVault;
					
			}
		}
	}
	
	return 0;
	
}

/*
_id is the id of the artifact to be activated
pVault is a pointer to an address of a pointer that points to the first Vault variable (the warehouse)
Go through the Vault structures in the warehouse and find the artifact with the same id as _id and
print its parameters
Return 1 only if an artifact with id the same as _id exsists, otherwise return 0
*/
void showArtifact(int _id,Vault** pVault)
{
	if((*pVault)!=NULL)
	{
		if((*pVault)->artifact!=NULL)
		{
			if((*pVault)->artifact->id==_id)
			{
				printf("Artifact id=%d:\n",(*pVault)->artifact->id);
				printf("Name: %s\n",(*pVault)->artifact->name);
				printf("Hazard Level: %d\n",(*pVault)->artifact->hazardLevel);
				printf("Active: %d\n",(*pVault)->artifact->active);
			}
			else
			{
				showArtifact(_id,&((* pVault)->nextVault));
			}

		}
	}
	else
	{
		printf("No artifact with id=%d\n",_id);
	}

}

/*
EXTRA CREDIT. Do not comment out the function. 
If you are not going to write the function leave as it is

pVault is a pointer to an address of a pointer that points to the first Vault variable (the warehouse)
Go through the Vault structures and sort the artifacts starting from the highest hazardLevel
*/
void sort(Vault** pVault)
{

	int swap=1;
	if((*pVault!=NULL)&&((*pVault)->nextVault!=NULL))
	{
		while(swap)
		{
			swap=0;
			Vault* t=*pVault;
			Vault* t1=t->nextVault;
	
			while(t1!=NULL)
			{
				if(t->artifact->hazardLevel<t1->artifact->hazardLevel)
				{
					Artifact* tA=t->artifact;
					t->artifact=t1->artifact;
					t1->artifact=tA;
					swap=1;
				}
				t=t->nextVault;
				t1=t1->nextVault;
			}
		}
	}
}
