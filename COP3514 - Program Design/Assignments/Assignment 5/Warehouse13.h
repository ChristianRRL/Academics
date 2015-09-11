#ifndef _Warehouse13H_
#define _Warehouse13H_

typedef struct 
{
	int id;
	int active;
	int hazardLevel;
	char *name;

}Artifact;

typedef struct Vault
{
	Artifact *artifact;
	struct Vault* nextVault;

}Vault;

int createArtifact(Artifact** pArtifact,int _id,int _hazardLevel,char _name[]);

int storeArtifact(Artifact* pArtifact,Vault** pVault);

int activate(int _id,Vault** pVault);

int neutralize(int _id,Vault** pVault);

void showArtifact(int _id,Vault** pVault);

void sort(Vault** pVault);

#endif
