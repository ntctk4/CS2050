/*
 *Nathaniel Callahan
 *ntctk4
 *Lab 3
 *Lab Code: "I'm not waring hocky pads!"
 *
 * */

#include<stdio.h>
#define MAX_ACCOUNTS 20

typedef struct
{
	int accountId;
	float ballance;
} Account;//a structure that holds both the account ID and the ballance in the account

int load_accounts(Account accounts[], char* fileName);
void sort(Account accounts[], int length);
Account* find_account(Account accounts[], int low, int high, int id);
void run_transactions(Account accounts[], int length, char* fileName);
void print(Account accounts[], int length);





int main(int argc, char* argv[])
{
	Account accounts[MAX_ACCOUNTS];
	int length;




	if(argc != 3)//checks to see if there is the correct number of files
	{
		printf("\n Incorrect number of command line arguments\n");
		return 0;
	}
	
	length = load_accounts(accounts, argv[1]);//puts account info from account file into an arry

	if(length == 0)
	{
		printf("\nUnable to open the input file\n");
		return 0;
	}
	



	sort(accounts, length);

	run_transactions(accounts, length, argv[2]);

	print(accounts, length);


	return 0;
}

int load_accounts(Account accounts[], char* fileName)//opens account file and puts the info in the array and closes the file. returns the number of accounts
{
	int i = 0;

	FILE* file=fopen(fileName, "r");

	if (file==NULL)
		return 0;

	while (1)
	{
		fscanf(file,"%d %f", &accounts[i].accountId, &accounts[i].ballance);

		if(feof(file) || i > MAX_ACCOUNTS)
		{
			break;
		}
	i++;
	
	}
	fclose(file);
	return i;

}

void sort(Account accounts[], int length)//sorts the accounts in the array in order by the account ID. Lowest ID first largest last.
{
	int pass;
	Account hold;
	int i;

	for(pass=1; pass<length; ++pass)
	{
		for(i=0; i<length-1; i++)
		{
			if(accounts[i].accountId > accounts[i + 1].accountId)
			{
				hold = accounts[i];
				accounts[i] = accounts[i + 1];
				accounts[i+1] = hold;
			}
		}
	}

}


Account* find_account(Account accounts[], int low,int high, int id)//searches for an account ID in the array. If not found if returns NULL.
{
	int middle = 0;


	middle = (low + high)/2;

	if(low > high)
	{
		return NULL;
	}

	if (id < accounts[middle].accountId)
	

		return find_account(accounts, low, middle-1, id);
	
	else if(id > accounts[middle].accountId)
		
		return find_account(accounts, middle+1, high, id);
	
	else
		
		return &accounts[middle];
}




void run_transactions(Account accounts[], int length, char* fileName)// Adds, subtracts from the accounts, or sends error message if no account or if account goes below zero.
{

	int i=0;
	Account* accountPtr;
	int id = 0;
	float change = 0;


	FILE* file=fopen(fileName, "r");


	while (1)
	{
		fscanf(file, "%d %f", &id, &change);


	
		if(feof(file))
		{
			break;
		}

		
		accountPtr = find_account(accounts, 0, length, id);

		if(accountPtr == NULL)
		
			printf("Invalid transaction; account %d does not exist", id);
		

		else if (accounts[i].ballance + change < 0)
		{
			printf("\nInvalid transaction; Withdrawing $%.2f from account %d results in a negative balance", change, id);
		
			i++;
		}

		else 
		{	
			accounts[i].ballance = accounts[i].ballance + change;
		
			i++;
		}

	
	
	}	
	
	fclose(file);


}	

void print(Account accounts[], int length)//prints out the accounts ID and the ballance after the transactions take place.
{
	int i;
	
	printf("\n\nFinal balance sheet");

	for(i=0; i<length; i++)

		printf("\n %d %.2f", accounts[i].accountId, accounts[i].ballance);

	printf("\n");

}
