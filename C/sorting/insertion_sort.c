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
void generate_random_numbers(int *array, int n)
{

    for(int i = 0; i < n; i++)
    {
        *(array + i) = rand() %100 + 1;
    }
}

void insertion_sort(int *array, int size)
{
    int j, key;
    for(int i = 0; i < size; i++)
    {
        j = i - 1;
        key = *(array + i);

        while(j >= 0 && key < *(array + j))
        {
            *(array + (j + 1)) = *(array + j);
            j = j - 1;
        }

        *(array + (j + 1)) = key;
    }
}

int main(int argc, const char *argv[])
{
    int size;
    printf("Enter the size of the array: ");
    scanf("%d",&size);

    int array[size];

    /*Generating random numbers and filling the array with them*/
    generate_random_numbers(array, size);

    printf("Before sorting: \n");
    display(array, size);

    insertion_sort(array, size);

    printf("After sorting: \n");
    display(array, size);

    return 0;
}