#include "function.h"
#include<stdio.h>

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		printf("Usage: %s Nathan\n");
		return 1;
	}

	displayMessage(argv[1]);

	return 0;
}
