#include <iostream>
#include <unordered_map>

using namespace std;

void printAllSubarrays(int arr[], int n) {
    /*
    * Create an empty multimap to store the ending
    * index of all subarrays having the same sum
    */
    unordered_multimap<int, int> map;

   /*
   * Insert (0, -1) pair into the map to
   * handle the case when subarray with
   * zero-sum starts from index 0
   */
   map.insert(pair<int, int>(0, -1));

   int sum = 0;

   for(int i = 0; i < n; i++) {
       sum += arr[i];

       /*
       * If the sum is seen before, there exists at least
       * one subarray with zero-sum
       */
       if(map.find(sum) != map.end()) {
           auto it = map.find(sum);

           // Find all subarrays with the same sum
           while(it != map.end() && it->first == sum) {
               //cout << "Subarray [" << it->second + 1 << "..." << i << "]" << endl;
               it++;
           }
       }
       // Insert (sum so far, current index) pair into the multimap
       map.insert(pair<int, int>(sum, i));
   }

   for(auto &x : map) {
       cout << x.first << " " << x.second << endl;
   }

}

int main() {
    int arr[] = {3, 4, -7, 3, 1, 3, 1, -4, -2, -2};
    int n = sizeof(arr)/sizeof(arr[0]);

    printAllSubarrays(arr, n);

    return 0;
}