#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::vector;
using std::string;

class Node {
    public:
        int key;
        Node* next;
};

//Utility function
Node* newNode(int key, Node* next) {
    Node* node = new Node;
    node->key = key;

    node->next = next;

    return node;
}

//Function for linked list implementation
Node* constructList(vector<int> const &keys) {
    Node* head, *node = nullptr;

    for(int key: keys) {
        node = newNode(key, node);
        head = node;
    }

    return head;
}

//Function to add a new node at the end of the link list
void push(int key, Node* head) {
    Node* node, *ptr = head;
    
    while(ptr->next) {
        ptr = ptr->next;
    }

    node = new Node;
    node->key = key;
    node->next = nullptr;

    ptr->next = node;
}

//Helper function to print a linked list
void printList(Node* head) {
    Node* ptr = head;
    while(ptr) {
        cout << ptr->key << " ";
        ptr = ptr->next;
    }
    cout <<endl;
}

int main(int argc, const char* argv[]) {

    vector<int> keys = {9, 7, 5, 3, 1};

    Node* head = constructList(keys);

    printList(head);

    push(13, head);

    printList(head);

    return 0;
}