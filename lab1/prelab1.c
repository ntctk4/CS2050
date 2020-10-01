#include<stdio.h>
#define MAX_ARR_LEN 20

int numbers[MAX_ARR_LEN];

int read_numbers_from_file();
float average(int length);
int find_max(int length);
void print_numbers(int length);

int main(void)
{


	int length = read_numbers_from_file();

	if(length==0)
	{
		printf("\nUnable to open the input file\n");
		return 0;
	}

	print_numbers(length);
	float ave = average(length);
	int max= find_max(length);

	printf("The average of the list is %f\n", ave);
	printf("The largest number in the list is %d\n", max);

	return 0;
}

int read_numbers_from_file(void)
{
	int i=0;
	int size;
	FILE* file=fopen("data.txt", "r");	

	if(file==NULL)
	{
		return 0;
	}
	
	fscanf(file, "%d", &size);

	if(size < MAX_ARR_LEN)
	{
		for(i=0; i<size; i++)
			fscanf(file, "%d", &numbers[i]);
	}
		else 
		{
			for(i=0; i<MAX_ARR_LEN; i++)
				fscanf(file, "%d", &numbers[i]);
		}

	fclose(file);
	return size;

}

float average(int length)
{
	float sum;
	int total=0;
	int i;

	for(i=0; i<length; i++)
	{
		total += numbers[i];
	}

	sum = (float)total/length;

	return sum;
}

int find_max(int length)
{
	int i;
	int index;
	int m=0;

	for(i=0; i<length; i++)
	{
		if (numbers[i] > m)
		{

			m = numbers[i];
			index = i;
		}
	}

	return m;
}

void print_numbers(int length)
{
	int i;

	for(i=0; i<length; i++)
	{
		printf("\n%d", numbers[i]);
	}
	printf("\n");
}
