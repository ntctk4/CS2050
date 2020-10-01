/*
 *Nathaniel Callahan
 *ntctk4
 *Lab 4
 *Lab Code: Daft Punk
 *
 */
#include<stdio.h>
#define MAX_ARR_LEN 1000

void mergesort(int array[], int low, int high);
void merge(int array[], int low, int mid, int high);
int magic_index(int array[], int low, int high);
int populate_array(int array[], char* fileName);
int is_sorted(int array[], int length);

int main(int argc, char* argv[])//Calls populate, merge, sorted, and magic numbers functions and prints out the sorted array of numbers and a magic number if ther is one.
{
	int len=0;
	int magic_num;
	int i;



	if(argc != 2)
	{
		printf("\n Incorrect number of command line arguments\n");
		return 0;
	}

	int array[MAX_ARR_LEN];
	
	len = populate_array(array, argv[1]);



	mergesort(array, 0, len-1);

	is_sorted(array, len);

	magic_num = magic_index(array, 0, len-1);

	printf("\nSorted Number Array:\n");
	
	for(i=0; i<len; i++)
	{
		printf("%d \n", array[i]);
	}


	if(magic_num == -1)
		printf("\nNo magic number found\n");

	else
		printf("\nMagic number is %d\n", array[magic_num]);

	return 0;

}

void mergesort(int array[], int low, int high)// Splits the array in half and recusivly merge sorts the array.
{
	int middle;
	

	if((high - low) >= 1)
	{
	middle = (low + high)/2;
	

	mergesort(array, low, middle);
	mergesort(array, middle+1, high);

	merge(array, low, middle, high);
	}
}

void merge(int array[], int low, int middle, int high)//takes the two halfs of the array and puts them together as a merged sorted array. It starts out as one array with the left half sorted and the right half sorted, but not sorted together.
{

	int leftIndex = low;
	int rightIndex = middle + 1;
	int combinedIndex = low;
	int tempArray[MAX_ARR_LEN];
	int i;

	while(leftIndex <= middle && rightIndex <= high)
	{
		if(array[leftIndex] <= array[rightIndex])
			tempArray[combinedIndex++] = array[leftIndex++];
		else
			tempArray[combinedIndex++] = array[rightIndex++];
	}

	if(leftIndex == middle + 1)
	{
		while(rightIndex <= high)
			tempArray[combinedIndex++] = array[rightIndex++];
	}
	
	else
	{
		while(leftIndex <= middle)
			tempArray[combinedIndex++] = array[leftIndex++];
	}

	for(i = low; i <= high; i++)
		array[i] = tempArray[i];

}

int magic_index(int array[], int low, int high)//uses a binary search to find if middle is equal to array[middle]. If it does it returns the value middle, if not the function returns -1, a value that can not be a magic number since there is no such thing as array[-1].
{

	int middle;

	middle = (low + high)/ 2;

	if(low > high)
		return -1;

	if(middle < array[middle])

		middle = magic_index(array, low, middle-1);

	if(middle > array[middle])
		
		middle = magic_index(array, middle+1, high);

	return middle;
}

int populate_array(int array[], char* fileName)//Opens up the input file and loads the array with the numbers in the file. Stops at the end of the file or if i>MAX_ARR_LEN (1000). returns i which is the length of the array.
{
	int i = 0;

	FILE* file=fopen(fileName, "r");

	if (file==NULL)
		return 0;

	while (fscanf(file, "%d", &array[i]) != EOF)
	{

		if(i > MAX_ARR_LEN)
		{
			break;
		}

		i++;
	}

	fclose(file);

	return i;
}

int is_sorted(int array[], int len)//This function finds out if the array is sorted. It will return 1 if the array is sorted and 0 if it is not.
{
	int i;

	for(i=0; i<len-1; i++)
	{
		if(array[i] > array[i+1])
		{
			return 0;
		}
	}
	return 1;
}
