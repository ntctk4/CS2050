/*
 *Nathaniel Callahan
 *10255588
 *August 29 2014
 *Lab section: E
 *Lab Code: (Spoiler: 'Coffee')
 * */

#include<stdio.h>
#define MAX_ARR_LEN 20

typedef struct
{
	char title [20];// an array that holds the names of movies
	int yearReleased;// holds the year the movie is released
	int sales;//holds the sales values for the movies
	int ticketsSold;// holds the value for the number of tickets sold
} Movie;//a structure for the movie catalog on the data.txt fiel

Movie movie_catalog[MAX_ARR_LEN];//an array that holds all the info from each movie on the list

int populate_movie_catalog();
float average_ticket_price(int length);
int find_highest_grossing_movie(int length);
void print_catalog(int length);

int main(int argc, char* argv[])
{
	int length;//The number of movies in the catalog
	float avg;//The variable to hold the value of average ticket price
	int max;//variable that holds the name of the highest grossing movie on the list

	length = populate_movie_catalog();

	if(length==0)
	{
		printf("\nUnable to open the input file\n");
		return 0;
	}
	
	avg = average_ticket_price(length);//assigns average ticket price to avg
	max = find_highest_grossing_movie(length);//assigns the spot in the array the highest grossing movie is
	print_catalog(length);//prints the movies and release dates from the catalog
	
	printf("\nAverage Ticket Price: $%.2f\n", avg);
	printf("Highest Grossing Movie: %s\n", movie_catalog[max].title);

	return 0;
}

int populate_movie_catalog(void)//function that brings the info from the data.txt file into the movie catalog array
{
	int i=0;//place holder for the for loop
	int length;//variable for the number of movies on the list
	
	FILE* file=fopen("data.txt", "r");//opens up the text file

	if(file==NULL)
	{
		return 0;
	}

	fscanf(file, "%d", &length);//assigns the number of movies on the list to the length variable

	if(length < MAX_ARR_LEN)//puts each movie's info into the array if length is less than MAX_ARR_LEN 
	{
		for(i=0; i<length; i++)
			fscanf(file,"%s %d %d %d", movie_catalog[i].title, &movie_catalog[i].yearReleased, &movie_catalog[i].sales, &movie_catalog[i].ticketsSold);
	}

	
	else
	{
		for(i=0; i<MAX_ARR_LEN; i++)//puts MAX_ARR_LEN (20) movies in the catalog array if length is greater than MAX_ARR_LEN
			fscanf(file,"%s %d %d %d", movie_catalog[i].title, &movie_catalog[i].yearReleased, &movie_catalog[i].sales, &movie_catalog[i].ticketsSold);
	}

	
	fclose(file);//closes the data.txt file
	return length;//function returns length
}

float average_ticket_price(int length)//This function finds the average ticket price of the movie catalog 
{
	float sum;//variable for average ticket price
	int totalTickets = 0;//variable to hold the total number of tickets sold
	int totalSales = 0;//variable to hold the total amount earned from all the movies
	int i;//place holder in the for loop

	for(i=0; i<length; i++)
	{
		totalTickets += movie_catalog[i].ticketsSold;
	
		totalSales += movie_catalog[i].sales;
	}


	sum = (float)totalSales/totalTickets;

	return sum;// returns the value of the average ticket price
}

int find_highest_grossing_movie(int length)//finds the movie that made the most money
{
	int i;//place holder in the for loop
	int max = 0;// variable that holds highest grossing movie's earnings
	int index;//holds the spot in the array that has the highest grossing movie

	for(i=0; i<length; i++)
	{
		if(movie_catalog[i].sales > max)
		{
			max = movie_catalog[i].sales;

			index = i;
		}
	}

	return index;//returns the array spot that holds the highest grossing move
}

void print_catalog(int length)//prints on the screen the list of movies and what year they came out
{
	int i;//place holder in the for loop

	printf("List of Movies:");

	for(i=0; i<length; i++)
	{
		printf("\n%s : %d", movie_catalog[i].title, movie_catalog[i].yearReleased);
	}

	printf("\n");

}
