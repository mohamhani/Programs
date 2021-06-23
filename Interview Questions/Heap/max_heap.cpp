#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

using namespace std;

// Max Heap implementation in C++

class PriorityQueue {
    private:
        // Vector to store heap elements
        vector<int> A;

        /*
        * Return parent
        */
       int parent(int i) {
           return (i - 1) / 2;
       }

       // Return left child
       int leftChild(int i) {
           return (2*i + 1);
       }

       // Return right child
       int rightChild(int i) {
           return (2*i + 2);
       }

       /*
       * Recursive heapify-down algorithm.
       * The node at index `i` and its two children
       * violates the heap property
       */
       void heapify_down(int i) {
           int right = rightChild(i);
           int left = leftChild(i);

           int largest = i;

           /*
           * Compare A[i] with its left and right child
           * and find the largest value
           */
           if(left < size() && A[left] > A[largest]) {
               largest = left;
           }

           if(right < size() && A[right] > A[largest]) {
               largest = right;
           }

           /*
           * Swap with the child having greater value
           * and call heapify_down on the child
           */
           if(largest != i) {
               swap(A[i], A[largest]);
               heapify_down(largest);
           }
       }

        /*
        * Check if the node at index `i` and its parent
        * violate the heap property
        */
        void heapify_up(int i) {
            if(i && A[parent(i)] < A[i]) {
                swap(A[i], A[parent(i)]);
                heapify_up(parent(i));
            }
        }

    public:
        int size() {
            return A.size();
        }

        bool empty() {
            return size() == 0;
        }

        void push(int key) {
            A.push_back(key);

            // Get element index and call heapify_up
            int index = size() - 1;
            heapify_up(index);
        }

        /*
        * Function to remove an element with 
        * the highest priority (present at the root)
        */
        void pop() {
            try {
                if(size() == 0) {
                    cout << "Heap underflow" << endl;
                    return;
                }

                /*
                * Replace the root of the heap with
                * the last element of the vector
                */
               A[0] = A.back();
               A.pop_back();

               heapify_down(0);
            }
            catch(const out_of_range &oor) {
                cout << endl;
                cout << oor.what() << endl;
            }
        }

        int top() {
            try {
                if(size() == 0) {
                    throw out_of_range("Heap is underflow");
                }

                // Otherwise, return the top element
                return A.at(0);
            }
            // Catch and print the exception
            catch(const out_of_range &oor) {
                cout << endl;
                cout << "Out of range error" << oor.what() << endl;
            }
        }

};

int main()
{
    PriorityQueue pq;
 
    // Note: The element's value decides priority
 
    pq.push(3);
    pq.push(2);
    pq.push(15);
 
    cout << "Size is " << pq.size() << endl;
 
    cout << pq.top() << " ";
    pq.pop();
 
    cout << pq.top() << " ";
    pq.pop();
 
    pq.push(5);
    pq.push(4);
    pq.push(45);
 
    cout << endl << "Size is " << pq.size() << endl;
 
    cout << pq.top() << " ";
    pq.pop();
 
    cout << pq.top() << " ";
    pq.pop();
 
    cout << pq.top() << " ";
    pq.pop();
 
    cout << pq.top() << " ";
    pq.pop();
 
    cout << endl << boolalpha << pq.empty();
 
    pq.top();    // top operation on an empty heap
    pq.pop();    // pop operation on an empty heap
 
    return 0;
}