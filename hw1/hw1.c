#include<stdio.h>
#include<string.h>

#define STRING_LEN 20
#define PLAYLIST_LEN 20

typedef struct
{
	char artist[STRING_LEN];
	char album[STRING_LEN];
	char title[STRING_LEN];
	int rating;
}Song;//structure that holds the artist, album, title, and rating.

int build_playlist(Song playlist[], char* inputFiles[], int numInputFiles);
int is_member(Song playlist[], int len, char* title);
void sort(Song playlist[], int len);
int do_swap(Song first, Song second);
void print(Song playlist[], int len);

int main(int argc, char* argv[])//checks to see if there is enough input files, creates a playlist array, gives an error message if there are duplicate songs, calls sort print and returns 0.
{
	int len;
	
	if(argc < 2)
	{
		printf("Incorrect number of command line arguments\n");
		printf("Correct usage: %s <input 1> <input 2> ...<input n>\n", argv[0]);
		return -1;
	}

	Song playlist[PLAYLIST_LEN];

	len = build_playlist(playlist, argv + 1, argc -1);


	if (len == -1)
	{
		printf("Invalid input: multiple songs with the same title");
		return 0;
	}

	sort(playlist, len);
	print(playlist, len);

	return 0;
}

int build_playlist(Song playlist[], char* inputFiles[], int numInputFiles)//opens up the input files and put each string/number in a varable. then calls is_member to check for duplicares, then fill the array with the valuse. once this function goes through all the files and closes them it retuns the length of the playlist array to main.
{
	int i;
	int len=0;
	char artist[STRING_LEN];
	char album[STRING_LEN];
	char title[STRING_LEN];
	int rating;
	int result;
	
	for(i=0; i<numInputFiles; i++)
	{	
		FILE* file=fopen(inputFiles[i], "r"); 

		if (file == NULL)
		{
			printf("\nUnable to open input file\n");
			return 0;
		}

		while (fscanf(file, "%s %s %s %d", artist, album, title, &rating) != EOF)
		{



			result = is_member(playlist, len, title);

			if(result == 0)
			{
				strcpy(playlist[len].artist, artist);
				strcpy(playlist[len].album, album);
				strcpy(playlist[len].title, title);
				playlist[len].rating = rating;
				
				len++;
			}

			else 
				return -1;

		if( len > PLAYLIST_LEN)
		{
			break;
		}

		}
		fclose(file);
	}

	return len;	
}

int is_member(Song playlist[], int len, char* title)//Checks for duplicate song titles. If there are duplicates return -1 otherwise 0.
{
	int i;
	int result;

	for(i=0; i<len; i++)
	{
		result=strncmp(title, playlist[i].title, STRING_LEN); 
		if(result == 0)
			return -1;
	}

	return 0;
}

void sort(Song playlist[], int len)//Uses a bubble sort to sort through the array. Uses do_swap if the songs need to be swiched.
{
	int pass;
	Song hold;
	int i;

	for (pass = 1; pass < len; ++pass)
	{
		for(i=0; i<len-1; ++i)
		{
			if(do_swap(playlist[i], playlist[i+1]) == 1)
			{
				hold = playlist[i];
				playlist[i] = playlist[i+1];
				playlist[i+1] = hold;
			}
		}
	}

}

int do_swap(Song first, Song second)//compares two playlist arrays to sort in alphabetical order in the order of artist , album, title. Doesn't sort by rating
{
	int i;

	int artist = strncmp(first.artist, second.artist, STRING_LEN);
	int album = strncmp(first.album, second.album, STRING_LEN);
	int title = strncmp(first.title, second.title, STRING_LEN);

	if(artist > 0)
		return 1;

	if(artist == 0)
	{
		if(album > 0)
			return 1;
	
		if(album == 0)
		{
			if(title > 0)
				return 1;

		}
	}
	return 0;
}

void print(Song playlist[], int len)//Takes the song playlist and length and prints out the array for the user to see. It pads the artist by 10, album by 12, title by 10 and rating by 4.
{
	int i;

	for(i = 0; i<len; i++)
	{
		printf("\n%10s %12s %10s %4d", playlist[i].artist, playlist[i].album, playlist[i].title, playlist[i].rating);
	}

	printf("\n");
}
