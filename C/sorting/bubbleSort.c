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

int main(int argc, const char * argv[])
{
    int size;
    printf("Enter the size of the array: ");
    scanf("%d",&size);

    int array[size];

    /*Generating random numbers and filling the array with them*/
    generateRandomNumbers(array, size);

    printf("Before sorting: \n");
    display(array, size);

    bubbleSort(array, size);

    printf("After sorting: \n");
    display(array, size);

    return 0;

}
