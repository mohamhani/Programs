#include <stdio.h>
#include <stdlib.h>

void display(int *array, int size) {
    for(int i = 0; i < size; i++) 
    {
        printf("a[%d] : %d\n", i, *(array + i));
    }
    printf("\n");
}

/*Function to swap two values*/
void swap(int *num1, int *num2) 
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

void merge(int *array, int left, int mid, int right)
{
    int i, j, k;
    int left_size = mid - left + 1;
    int right_size = right - mid;

    int left_side[left_size];
    int right_side[right_size];

    /*Copy the contents of the array to the left array and right array*/
    for(i = 0; i < left_size; i++)
    {
        left_side[i] = *(array + (left + i));
    }
    for(j = 0; j < right_size; j++)
    {
        right_side[j] = *(array + (mid + j + 1));
    }

    /*Merge the temp arrays in to the original array*/
    i = 0, j = 0, k = left;
    while(i < left_size && j < right_size)
    {
        if(left_side[i] <= right_side[j])
        {
            *(array + k) = left_side[i];
            i++;
        }
        else
        {
            *(array + k) = right_side[j];
            j++;
        }
        k++;
    }

    /*Copy the remaining elements in to the main array*/
    while(i < left_size)
    {
        *(array + k) = left_side[i];
        i++;
        k++;
    }
    while(j < right_size)
    {
        *(array + k) = right_side[j];
        j++;
        k++;
    }

}

void merge_sort(int *array, int left, int right)
{
    if(left < right)
    {
        int mid = left + (right - left)/2;

        //Keep dividing the array into two halves
        merge_sort(array, left, mid);
        merge_sort(array, mid + 1, right);

        //Merge the divided array
        merge(array, left, mid, right);
    }
}


int main(int argc, const char * argv[])
{
    int size;
    printf("Enter the size of the array: ");
    scanf("%d",&size);

    int array[size];

    /*Generating random numbers and filling the array with them*/
    generate_random_numbers(array, size);

    printf("Before sorting: \n");
    display(array, size);

    merge_sort(array,0,  size-1);

    printf("After sorting: \n");
    display(array, size);

    //gcc -std=c11 merge_sort.c -o merge_sort

    return 0;
}