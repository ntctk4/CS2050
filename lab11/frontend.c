/*
 *Nathaniel Callahan
 *ntctk4
 *LAB E
 lab 11
 *Lab Code: last lab
 *
 * */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include "parser.h"







int main(int argc, char** argv)// opens input file calls all the check functions to check each token for name, phone number, date, and email. 
{
	int i = 0;
	int j = 0;
	int k = 0;
	int check =0;
	int words = 0;
	char* name;
	int MAX_LINE = 250;

	if(argc != 2)
	{
		printf("\n Incorrect number of command line arguments\n");
		return 0;
	}

	FILE* file=fopen(argv[1], "r"); 



	char* token = "";

	char buffer[MAX_LINE];

	while(fgets(buffer, MAX_LINE, file) != NULL)
	{
		if(buffer[strlen(buffer) - 1] == '\n')
		{
			buffer[strlen(buffer) - 1] = '\0';
		}

		token = strtok(buffer, " \n\r\t");

		while (token != NULL)
		{


			i = looks_like_name(token);

		


			if(i == 1 && k == 0)
			{ 
				name = token;
			}
			j = j + i;

			++k;

			if(k == 2 && j != 2)
			{
				k = 0;
				j = 0;
			}

			else 
			{
				printf("Name: %s %s\n", name, token);
				j = 0;
				k = 0;
			}

			i = is_phone_number(token);

			if(i == 1)
			{
				printf("Phone number: %s\n", token);
			}

			i = is_date(token);

			if(i == 1)
			{
				printf("Date: %s\n", token);
			}
		/**	i = is_email(token);

			if(i == 1)
			{
				printf("Email: %s\n", token);
			}**/

			token = strtok(NULL, " \n\r\t");

			words++;
		}
		printf("There are %d words in the file", words);
		close(file);
	}
	return 0;
}
