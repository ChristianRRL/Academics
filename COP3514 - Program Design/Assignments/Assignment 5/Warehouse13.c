#include "Warehouse13.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int createArtifact(Artifact** pArtifact,int _id,int _hazardLevel,char _name[])
{
	(*pArtifact) = malloc(sizeof(Artifact));	//allocates memory for the structure
	
	if ((*pArtifact) == NULL)
	{
		printf("Error allocating memory\n");
		return 0;
	}

	//pArtifact is an address to a pointer
	//*pArtifact is the actual pointer

	(*pArtifact)->name = malloc(((int)strlen(_name) + 1) * sizeof(char));	//allocate memory for the char array inside of the structure
	if ((*pArtifact)->name == NULL)
	{
		printf("Error allocating memory\n");
		return 0;
	}
	
	(*pArtifact)->id = _id;
	
	(*pArtifact)->hazardLevel = _hazardLevel;
	(*pArtifact)->active=0;
	strcpy((*pArtifact)->name, _name);
	
	return 1;
}

int storeArtifact(Artifact* pArtifact,Vault** pVault)
{
	if ((*pVault) == NULL)
	{
		(*pVault) = (Vault*) malloc(sizeof(Vault));
		if ((*pVault) == NULL)
		{
			printf("Error allocating memory\n");
			return 0;
		}
		(*pVault)->artifact = pArtifact;
		(*pVault)->nextVault = NULL;
		
		return 1;
	}
	else
		return storeArtifact(pArtifact, &((*pVault)->nextVault));
	
	
	/*
	if ((*pVault) == NULL)
	{
		printf("Error allocating memory\n");
		return 0;
	}
	(*pVault)->
	return 0;
	*/
}

int activate(int _id,Vault** pVault)
{
	if ((*pVault) == NULL)
	{
		return 0;
	}
	else
	{
		if (((*pVault)->artifact->id == _id))
		{
			(*pVault)->artifact->active = 1;
			return 1;
		}
		else
		{
			//activate(_id, &((*pVault)->nextVault));
			return activate(_id,&((*pVault)->nextVault));
		}
	}
}

int neutralize(int _id,Vault** pVault)
{
	if((*pVault) == NULL)
		return 0;

	if ((*pVault)->artifact->id == _id)
	{
		Vault* temp = (*pVault);
		(*pVault) = (*pVault)->nextVault;
		free(temp);
		temp = NULL;
		return 1;
	}
	else
	{
		Vault* temp = (*pVault);
		Vault* temp1 = (*pVault);
		while ((temp != NULL) && (temp->artifact->id != _id))
		{
			temp1 = temp;
			temp = temp->nextVault;
		}
		if ((temp != NULL) && (temp->artifact->active == 1))
		{
			temp1->nextVault = temp->nextVault;
			free(temp);
			temp = NULL;
			return 1;
		}
		else
			return 0;
	}

		return 0;
	/*
	return 0;
	*/
}

void showArtifact(int _id,Vault** pVault)
{
	if ((*pVault) == NULL)
	{
		//printf("No artifact with id=%d found\n", _id);
	}
	else
	{
		if ((*pVault)->artifact->id == _id)
		{
			printf("Artifact id=%d:\n", (*pVault)->artifact->id);
			printf("Name: %s\n", (*pVault)->artifact->name);
			printf("Hazard level: %d\n", (*pVault)->artifact->hazardLevel);
			printf("Active: %d\n", (*pVault)->artifact->active);
			printf("\n");
		}
		else
			showArtifact(_id, &((*pVault)->nextVault));
	}
	return;
}

void sort(Vault** pVault)
{
	//struct part *cur, *prev, *new_node; aka: Vault *cur, *prev, *pVault
	struct Vault *cur, *prev;
	struct Vault *inventory = NULL;
	
	(*pVault) = malloc(sizeof(struct Vault));
	if ((*pVault) == NULL)
	{
		printf("Database is full; can't add more parts.\n");
		return;
	}
	
	//printf("Enter Vault hazard level: ");
	//scanf("%d", &(*pVault)->artifact->hazardLevel);
	
	for (cur = inventory, prev = NULL; cur != NULL && (*pVault)->artifact->hazardLevel > cur->artifact->hazardLevel; prev = cur, cur - cur->nextVault);
	
	if (cur != NULL && (*pVault)->artifact->hazardLevel == cur->artifact->hazardLevel)
	{
		printf("Vault already exists.\n");
		free(*pVault);
		return;
	}
	/*
	printf("Enter vault name: ");
	read_line((*pVault)->name, NAME_LEN);
	printf("Enter quantity on hand: ");
	scanf("%d", &(*pVault)->on_hand);
	
	(*pVault)->nextVault = cur;
	if (pref == NULL)
		inventory = (*pVault);
	else
		pref->nextVault = pVault;
	*/
}

/*
void sort(Vault** pVault)
{
	/*
	//use temp variables to sort the artifacts in hazard order
	
		if((*pVault) == NULL)
		return 0;

	if ((*pVault)->artifact->id == _id)
	{
		Vault* temp = (*pVault);
		(*pVault) = (*pVault)->nextVault;
		free(temp);
		temp = NULL;
		return 1;
	}
	else
	{
		Vault* temp = (*pVault);
		Vault* temp1 = (*pVault);
		while (temp != NULL)
		{
			temp1 = temp;
			temp = temp->nextVault;
		}
		if ((temp != NULL) && (temp->artifact->active == 1))
		{
			temp1->nextVault = temp->nextVault;
			free(temp);
			temp = NULL;
			return 1;
		}
	*/
	
	/*
	for (;;)
	{
		
	}
	
	if ((*pVault) == NULL)
	{
		//printf("Number not found\n");
	}
	else
	{
		if ((*pVault)->artifact->hazard)
	}
}
	*/