#include<assert.h>
#include<stdio.h>

int magic_numbers(int array[], int low, int high);

int main(void)
{
	int array1[] = {-1, 0, 2, 4, 7, 9, 10};
	assert(magic_numbers(array1, 0, 6) == 2);

	int array2[] = { -1, 0, 3, 4, 7, 9, 10};
	assert(magic_numbers(array2, 0, 6) == -1);

	printf("Congratulations! Your prelab Works!\n");
	
	return 0;
}

int magic_numbers(int array[], int low, int high)
{

	int middle;

	middle = (low + high)/ 2;

	if(low > high)
		return -1;

	if(middle < array[middle])

		middle = magic_numbers(array, low, middle-1);

	if(middle > array[middle])
		middle = magic_numbers(array, middle+1, high);

	return middle;
}
