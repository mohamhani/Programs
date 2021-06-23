#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *next;
};

class Queue {
    public:
        Node *front, *rear;
        Queue() {
            front = rear = NULL;
        }

        void enqueue(int item);
        void dequeue();
        void peek();
        ~Queue();
};

void Queue::enqueue(int item) {
    Node *temp = new Node;

    if(temp == NULL) {
        cout << "Overflow" << endl;
        return;
    }

    temp->data = item;
    temp->next = NULL;

    if(front == NULL) {
        front = rear = temp;
    }
    else {
        rear->next = temp;
        rear = temp;
    }
    cout << item << " has been Successfully added to the queue" << endl;
}

void Queue::dequeue() {
    Node *temp = NULL;
    if(front == NULL) {
        cout << "Underflow" << endl;
        return;
    }

    cout << front->data << " is being deleted" << endl;

    if(front == rear) {
        temp = front;
        front = rear = NULL;

        delete temp;
    }
    else {
        temp = front;
        front = front->next;
        delete temp;
    }
}

void Queue::peek() {
    if(front == NULL) {
        cout << "Queue is empty" << endl;
        return;
    }

    Node *temp = front;
    while(temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Queue::~Queue() {
    while(front != NULL) {
        Node *temp = front;
        front = front->next;
        delete temp;
    }
    rear = NULL;
}

int main() {

    Queue queue;
    queue.peek();

    queue.enqueue(10);
    queue.enqueue(24);
    queue.enqueue(28);
    queue.enqueue(32);
    queue.enqueue(30);

    queue.peek();

    queue.dequeue();
    queue.dequeue();
    queue.dequeue();

    queue.peek();

    queue.dequeue();
    queue.dequeue();

    queue.peek();

    cout << endl;
    cout << 9 % 10 << endl;

    return 0;
}