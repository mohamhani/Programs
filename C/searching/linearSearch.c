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

int linearSearch(int * array, int size, int value)
{
    for(int i = 0; i < size; i++) {
        if(array[i] == value)
        {
            return 1;
        }
    }

    return 0;
}  

void print(int * array, int size) {
    for(int i = 0; i < size; i++) 
    {
        printf("a[%d] : %d\n", i, *(array + i));
    }
    printf("\n");
}

int main()
{
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int array[size];

    generateRandomNumbers(array, size);

    int value = generateRandomNumber();

    
    printf("The array that is about to be searched.\n");
    print(array, size);

    if(linearSearch(array, size, value))
    {
        printf("Value %d is in the array.\n", value);
    }
    else
    {
        printf("Value %d is not in the array.\n", value);
    }
    
    //gcc -std=c11 linearSearch.c -o linearSearch
    return 0;
}
