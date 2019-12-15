#include <stdio.h>
#include <stdlib.h>

/*
* Generating random numbers for the linear search
*/
void generateRandomNumbers(int * array, int n)
{

    for(int i = 0; i < n; i++)
    {
        *(array + i) = rand() %100 + 1;
    }
}

/*
* Generating a random number between 1 to 99  
*/
int generateRandomNumber()
{
    int random = rand() %100 + 1;

    return random;
}

void swap(int * num1, int * num2) 
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void bubbleSort(int * array, int size)
{
    for(int i = 0; i < size - 1; i++)
    {
        for(int j = 0; j < size - 1 - i; j++)
        {
            if(*(array + j) > *(array + (j + 1)))
            {
                swap((array + j),(array + (j + 1))); 
            }
        }
    }
}

int binarySearch(int * array, int left, int right, int value)
{
    if (right >= 1)
    {
        int mid = left + (right - left)/2;

        //If the value is in the middle
        if(*(array + mid) == value)
        {
            return mid;
        }

        //If value is present in the left side
        if(*(array + mid) > value)
        {
            return binarySearch(array, left, mid - 1, value);
        }

        //If value is present in the right side
        if(*(array + mid) < value)
        {
            return binarySearch(array, mid + 1, right, value);
        }
    }

    //When the value isn't present in the array
    return -1;
}



void display(int * array, int size) {
    for(int i = 0; i < size; i++) 
    {
        printf("a[%d] : %d\n", i, *(array + i));
    }
    printf("\n\n");
}

int main()
{
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int array[size];

    generateRandomNumbers(array, size);

    int value = generateRandomNumber();

    
    printf("Before the array is sorted.\n");
    display(array, size);

    bubbleSort(array, size);

    printf("After the array is sorted.\n");
    display(array, size);

    
    if(binarySearch(array, 0, size - 1, value) == -1)
    {
        printf("Value %d is not in the array.\n", value);
    }
    else
    {
        printf("Value %d is in the array.\n", value);
    }
    
    
    //gcc -std=c11 binarySearch.c -o binarySearch
    return 0;
}
