/*
 *Nathaniel Callahan
 *ntctk4
 *lab 11
 *lab E
 *lab code:
 * */
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include "parser.h"

int is_phone_number(char* word)//checks to see if token is valid phone number. returns 1 if valid, 0 otherwise.
{
	int i = 0;

	while(word[i] != '\0')
	{
		i++;
	}

	if(i != 14)
	{
		return 0;
	}

	if(word[0] == '(' && word[4] == ')' && word[5] == '-' && word[9] == '-')
	{

		for(i=1; i<4; i++)
		{
			if(isdigit(word[i])==0)
				return 0;

		}

		for(i=6; i<9; i++)
		{
			if(isdigit(word[i])==0)
				return 0;
		}

		for(i=10; i<15; i++)
		{
			if(isdigit(word[i])==0)
				return 0;
		}

		return 1;
	}

	return 0;
}

int is_date(char* word)//checks to see if token is vaid date. returns 1 if valid date, 0 otherwise.
{

	int i = 0;
	int j = 0;
	int validDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	while(word[i] != '\0')
	{
		i++;
	}

	if(i != 10)
	{
		return 0;
	}

	if(word[2] == '/' && word[5] == '/')
	{

		word[2] = '\0';
		word[5] = '\0';

		i = atoi(word);
		
		if(0>i || i>12)
			return 0;
			
		j = atoi(&word[3]);

		if(j > validDays[i] || j<1)
			return 0;

		if(atoi(&word[6]) == 0)
			return 0;

		word[2] = '/';
		word[5] = '/';

		return 1;

	}

	return 0;

}

int looks_like_name(char* word)//checks to see if token is valid name. if it is it returns 1, otherwise 0.
{
	int i = 0;
	int j = 0;
	
	if(isupper(word[0]))
	{	
		i = strlen(word);

		for(j=1; j<i; j++)
		{

			if(isalpha(word[j]) == 0)
			{
					return 0;
			}

		}
		return 1;
	}
	return 0;
}

int is_email(char* word)// checks to see if token is a valid email. returns 1 if email, o otherwise
{

	int i = 0;
	int j = 0;

	while(word[i] != '\0')
	{
		if(word[i] == '@' && i != 0)
		{

			j = strlen(word);

			if(word[j-3] == '.' && word[j-2] == 'c' && word[j-1] == 'o' && word[j] == 'm' && word[j-4] != '@')
			{
				for(i+1; i<j; i++)
				{
					if(isalpha(word[i]) == 0)
						return 0;
				}

				return 1;
			}
		}
	}
	return 0;
}

