#include <stdio.h>
#include <stdlib.h>

void display(int * array, int size) {
    for(int i = 0; i < size; i++) 
    {
        printf("a[%d] : %d\n", i, *(array + i));
    }
    printf("\n");
}

/*Function to swap two values*/
void swap(int * num1, int * num2) 
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

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
* This method selects the lowest element in the array as a pivot
*/
int partition(int *array, int lower, int upper)
{
    int i = (lower - 1);

    int mid_point = (upper - lower)/2;

    int pivot = *(array + upper);

    for(int j = lower; j < upper; j++)
    {
        if(*(array + j) <= pivot)
        {
            i++;
            swap((array + i), (array + j));
        }
    }

    swap((array + (i + 1)), (array + upper));

    return i + 1;

}

void quick_sort(int *array, int lower, int upper)
{
    if(upper > lower)
    {
        int partition_index = partition(array, lower, upper);

        quick_sort(array, lower, partition_index - 1);
        quick_sort(array, partition_index + 1, upper);
    }
}

int main(int agrc, const char * argv[])
{
    int size;
    printf("Enter the size of the array: ");
    scanf("%d",&size);

    int array[size];

    /*Generating random numbers and filling the array with them*/
    generateRandomNumbers(array, size);

    printf("Before sorting: \n");
    display(array, size);

    quick_sort(array, 0, size - 1);

    printf("After sorting: \n");
    display(array, size);

    return 0;
}