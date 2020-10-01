/*
 *
 *Nathaniel Callahan
 *hw3
 *
 *
 * */
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include "stack.h"

#define MAX_EQU_LEN 100

static char prec(char operator)//checks to see if the operator is a *, /, %, +, or - and returns 5, 4, 3, 2, or 1 respectively. if not any or those then the function returns 0.
{
	if(operator == '*')
		return 5;

	else if(operator == '/')
		return 4;
	
	else if(operator == '%')
		return 3;

	else if(operator == '+')
		return 2;

	else if(operator == '-')
		return 1;

	else
		return 0;
}

static int isNumeric(char *num)//checks to see if the value sent to it is a number or not. returns 0 for a number and 1 if not a number. 
{
	while(*num != '\0')
	{
		if(isdigit(*num++) == 0)
			return 0;
	}
		return 1;

}

char* to_postfix(char* infix)//turns a math problem in infix form into its postfix form. Returns the postfix string to main.
{

	
	char* postfix = malloc(sizeof(char) * MAX_EQU_LEN);
	stack* s = create_stack();
	int i = 0;
	int j =0;

	
	for(i=0; infix[i]; i++)
	{
		if(isdigit(infix[i]))
		{
			postfix[j] = infix[i];
			j++;
			postfix[j] = ' ';
			j++;
		}

		else if(infix[i] == '(')
		{
			push(s, (char)infix[i]);
		}
		else if(prec(infix[i] != 0))
		{
			postfix[j] = ' ';

			while(!isEmpty(s) && (char)top(s) != '(')
			{
				postfix[j++] = (char)top(s);
				pop(s);
			}

			postfix[j++] = infix[i];
			j++;

		
		}

		else if(infix[i] == ')')
		{
			postfix[j] = ' ';
			j++;
				
		
			while(!isEmpty(s) && top(s) != '(')
			{
				postfix[j] =(char)top(s);
				pop(s);
				j++;
			}
			pop(s);
		}
	
	}

		while(!isEmpty(s))
		{
			postfix[j] = (char)top(s);
			free(s);
		}

		return postfix;
}



int eval(char* postfix)//evaluates the math problem in its postfix form and returns the result to main. 
{
	stack* s = create_stack();
	int result;

	char* token = strtok(postfix, "\n");
	while(token != NULL)
	{
		if(isNumeric(token))
		{
			push(s, atoi(token));
		}
		else
		{
			int x = top(s);
			pop(s);
			int y = top(s);
			pop(s);

			switch(token[0])
			{
				case '*' :
					result = y * x;
			       		break;
				case '/' :
					result = y / x;
					break;
				case '%' :
					result = y % x;
					break;
				case '+' :
					result = y + x;
					break;
				case '-' :
					result = y - x;
					break;
			}
			push(s, result);
		}
		token = strtok(NULL, "\n");
	}

	result = top(s);
	pop(s);
	free(postfix);
	free(s);

	return result;
}
