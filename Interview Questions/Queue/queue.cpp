#include <iostream>
#include <cstdlib>

using namespace std;

#define SIZE 10

class Queue {
    int *arr;
    int capacity, front, rear, count;

    public:
        Queue(int size = SIZE);
        ~Queue();

        void enqueue(int item);
        void dequeue();
        void peek();
        int size();
        bool isEmpty();
        bool isFull();
};

Queue::Queue(int size) {
    arr = new int[size];
    capacity = size;
    front = 0;
    rear = -1;
    count = 0;
}

void Queue::enqueue(int item) {
    if(isFull()) {
        cout << "Queue is full" << endl;
    }

    cout << item << " has been Successfully added to the queue" << endl;

    rear = (rear + 1) % capacity;
    arr[rear] = item;
    count++;
}

void Queue::dequeue() {
    if(isEmpty()) {
        cout << "Queue is empty" << endl;
        return;
    }

    cout << arr[front] << " is being removed" << endl;

    front = (front + 1) % capacity;
    count--;
}

void Queue::peek() {
    if(isEmpty()) {
        cout << "Queue is empty" << endl;
        return;
    }
    cout << endl;
    cout << "The front element is " << arr[front] << endl;
    cout << endl;
}

int Queue::size() {
    return count;
}

bool Queue::isEmpty() {
    return (size() == 0);
}

bool Queue::isFull() {
    return (size() == capacity);
}

Queue::~Queue() {
    delete[] arr;
}

int main() {
    Queue queue(5);

    queue.peek();
    
    queue.enqueue(3);
    queue.enqueue(5);
    queue.enqueue(9);
    queue.enqueue(11);
    queue.enqueue(13);

    queue.peek();

    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();

    queue.peek();


    return 0;
}