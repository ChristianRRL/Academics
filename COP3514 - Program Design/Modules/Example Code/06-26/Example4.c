#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Dynamic structure

typedef struct
{
	char* name; 
	int* value; 
}Person;


int create_person(Person** p,char name[],int value)//Person** p is a pointer to a pointer address! I know, it is confusing 
{

	 (*p)=malloc (sizeof(Person));			//allocate memory for the structure
	if((*p)==NULL)
	{
		printf("Memory allocation failed\n");
		return 0;	
	}
	//p is an address to a pointer
	//*p is the actual pointer
	(*p)->name=malloc (((int)strlen(name) + 1) * sizeof(char) );	//allocate memory for the char array inside of the structure
	if((*p)->name==NULL)
	{
		printf("Memory allocation failed\n");
		return 0;	
	}
	
	(*p)->value=malloc (sizeof(int));	//allocate memory for the int inside of the structure
	if((*p)->value==NULL)
	{
		printf("Memory allocation failed\n");
		return 0;	
	}

	//set the values
	strcpy((*p)->name,name); 
	*((*p)->value)=value;	 
	return 1;
}

void deletePerson(Person **p)
{

	free((*p)->value);
	(*p)->value=NULL;

	free((*p)->name);
	(*p)->name=NULL;

	free(*p);
	*p=NULL;
}

int main()
{
	 
	Person *p=NULL; //no memory is being allocated 
	char name[20];
	int val;

	printf("Enter name: ");
	scanf("%s",name);
	printf("\nEnter value: ");
	scanf("%d",&val);

	if((create_person(&p,name,val))==0)  //create memory and assign values
		return -1;
	
	printf("Name = %s value = %d\n",p->name,*(p->value));

	deletePerson(&p); //free the memory and set values to NULL
	if(p==NULL)
	{
		printf("Person deleted\n");
	}
	return 0;

}
