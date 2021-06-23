#include <iostream>

using namespace std;

/*
* For a given index i of an array size n
* 2 * i + 2 > n. Then A[i] represents a leaf node
* 2 * i + 2 < n. Then A[i] represents an internal heap node
*/
bool checkMinHeap(int A[], int n) {
    /*
    * Check for all internal nodes that their
    * right and left children (if present) holds
    * min-heap property
    */
   for(int i = 0; i <= (n - 2) / 2; i++) {
       if(A[i] > A[2*i + 1] || ((2*i + 2 != n) && A[i] > A[2*i + 2])) {
           return false;
       }
   }

   return true;
}

int main()
{
    int A[] = { 2, 3, 5, 8, 10 };
    int n = sizeof(A) / sizeof(int);
 
    if (checkMinHeap(A, n)) {
        cout << "The given array is a min-heap";
    }
    else {
        cout << "The given array is not a min-heap";
    }
 
    return 0;
}