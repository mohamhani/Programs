#include <iostream>
#include <vector>

using namespace std;

class PriorityQueue {
    private:
        // Return left child
       int leftChild(int i) {
           return (2*i + 1);
       }

       // Return right child
       int rightChild(int i) {
           return (2*i + 2);
       }

       void heapify(vector<int> &A, int i, int size) {
           int right = rightChild(i);
           int left = leftChild(i);

           int largest = i;

           /*
           * Compare A[i] with its left and right child
           * and find the largest value
           */
           if(left < size && A[left] > A[i]) {
               largest = left;
           }

           if(right < size && A[right] > A[largest]) {
               largest = right;
           }

           /*
           * Swap with the child having greater value
           * and call heapify_down on the child
           */
           if(largest != i) {
               swap(A[i], A[largest]);
               heapify(A, largest, size);
           }
       }

    public:
        // Constructor
        PriorityQueue(vector<int> &A, int n) {
            /*
            * Call heapify starting from the last
            * internal node all the way up to the root node
            */
           int i = (n - 2) / 2;
           while(i >= 0) {
               heapify(A, i--, n);
           }
        }

        int pop(vector<int> &A, int size) {
            if (size <= 0) {
                return -1;
            }

            int top = A[0];

            A[0] = A[size - 1];

            heapify(A, 0, size - 1);

            return top;
        }
};

void heapSort(vector<int> &A, int n) {
    PriorityQueue pq(A, n);

    while(n > 0) {
        A[n - 1] = pq.pop(A, n);
        n--;
    }
}

int main() {
    vector<int> A = { 6, 4, 7, 1, 9, -2 };
    int n = A.size();
 
    // perform heapsort on the array
    heapSort(A, n);
 
    // print the sorted array
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
 
    return 0;
}