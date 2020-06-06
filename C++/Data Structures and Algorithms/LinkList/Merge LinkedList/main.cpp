#include <iostream>
#include <cstdlib>


using namespace std;

struct node {
    int data;
    node* next;
};

typedef struct node* nodePtr;

nodePtr addNode(int data) {
    nodePtr newNode = new node;

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

nodePtr mergeLinkedList(nodePtr head1, nodePtr head2) {
    if(head1 == NULL) {
        return head2;
    }
    if(head2 == NULL) {
        return head1;
    }

    if(head1->data < head2->data) {
        head1->next = mergeLinkedList(head1->next, head2);
        return head1;
    }
    else {
        head2->next = mergeLinkedList(head1, head2->next);
        return head2;
    }
}

void displayList(nodePtr head) {
    nodePtr curr = head;
    while(curr != NULL) {
        cout << curr->data << " ";
        curr = curr -> next;
    }
}
    

int main(int argc, char** argv) {

    // 1->2->3->4->6
    nodePtr head1 = addNode(1);
    head1->next = addNode(2);
    head1->next->next = addNode(3);
    head1->next->next->next = addNode(4);
    head1->next->next->next->next = addNode(6);

    cout << "Head1" << endl;
    displayList(head1);
    cout << endl;

    // 1->3->5->7->8
    nodePtr head2 = addNode(1);
    head2->next = addNode(3);
    head2->next->next = addNode(5);
    head2->next->next->next = addNode(7);
    head2->next->next->next->next = addNode(8);

    cout << "Head2" << endl;
    displayList(head2);
    cout << endl;

    nodePtr mergedList = mergeLinkedList(head1, head2);

    cout << "Merged Link List" << endl;
    displayList(mergedList);
    cout << endl;



    return 0;
}