#include <iostream>
#include <unordered_set>

using namespace std;

bool hasZeroSumSubarray(int A[], int n) {
    /*
    * Function to check if subarray with
    * zero-sum is present in a given array
    * or not
    */
   unordered_set<int> set;

   /*
   * Insert zero into the set to handle the case
   * subarray with zero-sum starts from index 0
   */
   set.insert(0);

   int sum = 0;

   for(int i = 0; i < n; i++) {
       sum += A[i];

       if(set.find(sum) != set.end()) {
           return true;
       }
       else {
           set.insert(sum);
       }
   }

   return false;
}

int main() {
    int A[] = {4, 2, -3, -1, 0, 4};
    int n = sizeof(A)/sizeof(A[0]);

    hasZeroSumSubarray(A, n) ? cout << "Subarray exists" : cout << "Subarray doesn't exist";

    return 0;
}