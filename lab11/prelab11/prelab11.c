#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>


int is_phone(char* string);

int main(void)
{
	assert(is_phone("(123)-456-7890") == 1);
	assert(is_phone("(123) 456-7890") == 0);
	assert(is_phone("123-456-7890") == 0);
	assert(is_phone("(123)-45e-7890") == 0);
	assert(is_phone("(123)-456-789") == 0);

	printf("Yay !! \n");

	return 0;
}

int is_phone(char* string)
{
	int i = 0;

	while(string[i] != '\0')
	{
		i++;
	}

	if(i != 14)
	{
		return 0;
	}

	if(string[0] == '(' && string[4] == ')' && string[5] == '-' && string[9] == '-')
	{

	


	for(i=1; i<4; i++)
	{
		if(isdigit(string[i]) == 0)
				
				return 0;
			
	}

	for(i=6; i<9; i++)
	{
		if(isdigit(string[i]) == 0)

			return 0;
	}

	for(i=10; i<14; i++)
	{
		if(isdigit(string[i]) == 0)

			return 0;
	}

	return 1;
	}

	return 0;
	
}

