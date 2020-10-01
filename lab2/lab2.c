/*
 *Nathaniel Callahan
 *ntctk4
 *lab 2
 *September 12 2014
 *Lab section: E
 *Lab Code:"Black Tie"
 * */

#include<stdio.h>
#define MAX_LIBRARY_SIZE 30

typedef struct
{
	char title[20];
	char author[20];
	int rating;
} Book;//structure to hold title author and rating in their arrays.


int binary_search(Book library[], int low, int high, int key);
int populate_array(Book library[], char* input);
void sort(Book library[], int length);
void print(Book library[], int length, int key);



int main(int argc, char* arg)
{
	Book library[MAX_LIBRARY_SIZE]; 
	int length;
	int key;
	



	if (argc != 2)
	{
		printf("\n Incorrect number of command line arguments\n");
		return 0;
	}
	
	length  = populate_array(library, arg);

	if (length == 0)
	{
		printf("\nUnable to open the input file\n");
		return 0;
	}

	
	printf("Enter a rating to search for:");
	scanf("%d", &key);

	sort(library, length);
	
	key = binary_search(library, 0, length, key);


	print(library, length, key);

	return 0;
}






int populate_array(Book library[], char* input)//This function sets the size of the library arry and fills the arry
{
	int i = 0;
	int length;

	FILE* file=fopen("input.txt", "r");

	if (file==NULL)
		return 0;

	fscanf(file, "%d", &length);

	if(length < MAX_LIBRARY_SIZE)
	{
		for(i=0; i<length; i++)
			fscanf(file,"%s %s %d", library[i].title, library[i].author, &library[i].rating);
	}

		else
		{
			for(i=0; i<MAX_LIBRARY_SIZE; i++)
				fscanf(file, "%s %s %d", library[i].title, library[i].author, &library[i].rating);
		}

		fclose(file);
		return length;
}





int binary_search(Book library[], int low, int high, int key)//Searches to see if the key is in the rating array, returns if there oterwise returns -1.
{
	int middle;

	middle = (low + high)/ 2;

	if(low > high)
	{
		return -1;
	}

	if (key < library[middle].rating)

		middle = binary_search(library, low, middle-1, key);

	else if(key > library[middle].rating)
		
		middle = binary_search(library, middle+1, high, key);
	
	return middle;
}



void sort(Book library[], int length)//sorts the books, authors, and ratings by the size of rating. Smallest rating first, largest rating last.
{
	int pass;
	Book hold;
	int i;

	for(pass = 1; pass < length; ++pass)

	{
		for(i=0; i<length-1; ++i)
		{
	
		if(library[i].rating > library[i + 1].rating)
		{
			hold = library[i];
			library[i] = library[i+1];
			library[i+1] = hold;
		}
		
		}
	}	

}


void print(Book library[], int length, int key)//prints out the books, authors and ratings in order of rating, puts 3 * in front of book if it had the key value.

{
	int i;

	for(i=0; i<length; i++)

		if(i == key)
		{
			printf("\n***%s %s %d", library[i].title, library[i].author, library[i].rating);
		}
		
		else
			printf("\n%s %s %d", library[i].title, library[i].author, library[i].rating);

	printf("\n");
}

	
