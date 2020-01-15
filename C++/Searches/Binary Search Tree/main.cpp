#include <iostream>
#include <cstdlib>

#include "BST.cpp"

using namespace std;

int main(int argc, char** argv) {

    int treeData[16] = {50, 76, 21, 4, 32, 64, 15, 52, 14, 100, 83, 2, 3, 70, 87, 80};

    BST tree; 
    int input = 1;

    cout << "Printing the tree in order \nBefore adding numbers" << endl;

    tree.printInOrder();

    for(int i = 0; i < 16; i++) {
        tree.addLeaf(treeData[i]);
    }

    cout << "Printing the tree in order \nAfter adding numbers" << endl;

    tree.printInOrder();

    cout << endl;

    

    int smallest = tree.findSmallest();

    cout << "The smallest : " << tree.findSmallest() << endl;

    cout << "Enter a key value to delete, Enter -1 to stop the process" << endl;

    while(input != -1) {
        cout << "Enter key: ";
        cin >> input;
        {
            if(input != -1) {
            cout << endl;
            tree.removeNode(input);
            tree.printInOrder();
            cout << endl;
            }
        }
        
    }



    return 0;
}

