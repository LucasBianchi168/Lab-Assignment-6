#include <stdio.h>
#include <stdlib.h>

int search(int numbers[], int low, int high, int value) 
{
	if (low > high) {
		// if the lower bound somehow gets larger than the upper bound
		return -1;
	}
	else {
		int mid = (low + high) / 2; // take the middle value between the bounds
		if (numbers[mid] > value) {
			// this will occur if the value is to the left of index mid
			return search(numbers, low, high - 1, value);
		}
		 else if (numbers[mid] < value) {
			// this will occur if the value is to the right of index mid
			return search(numbers, low + 1, high, value);
		}
		else if (numbers[mid] == value) {
			// this will occur once the value is at index mid
			return mid;
		}
	}
}

void printArray(int numbers[], int sz)
{
	int i;
	printf("Number array : ");
	for (i = 0;i<sz;++i)
	{
		printf("%d ",numbers[i]);
	}
	printf("\n");
}

int main(void)
{
	int i, numInputs;
	char* str;
	float average;
	int value;
	int index;
	int* numArray = NULL;
	int countOfNums;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &countOfNums);
		numArray = (int *) malloc(countOfNums * sizeof(int));
		average = 0;
		for (i = 0; i < countOfNums; i++)
		{
			fscanf(inFile," %d", &value);
			numArray[i] = value;
			average += numArray[i];
		}

		printArray(numArray, countOfNums);
		value = average / countOfNums;
		index = search(numArray, 0, countOfNums - 1, value);
		if (index >= 0)
		{
			printf("Item %d exists in the number array at index %d!\n",value, index);
		}
		else
		{
			printf("Item %d does not exist in the number array!\n", value);
		}

		free(numArray);
	}

	fclose(inFile);
}