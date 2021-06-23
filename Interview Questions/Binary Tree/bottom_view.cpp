#include <iostream>
#include <map>

using namespace std;

struct Node {
    int data;
    Node *right, *left;

    Node(int data) {
        this->data = data;
        this->right = this->left = nullptr;
    }
};

void printBottom(Node *node, int dist, int level, map<int, pair<int, int>> &map) {
    if(node == nullptr) {
        return;
    }
    

    /*
    * If the current level is more than or equal to the
    * maximum level seen so far for the same horizontal distance or  
    * horizontal distance is seen for the first time, update the map
    */
    if(level >= map[dist].second) {
        map[dist] = {node->data, level};
    }

    /*
    * Recursive for the left subtree by decreasing
    * hozizontal distance and increasing level by one
    */
    printBottom(node->left, dist - 1, level + 1, map);

    /*
    * Recursive for the left subtree by increasing both
    * hozizontal distance and level by one
    */
    printBottom(node->right, dist + 1, level + 1, map);
}

void printBottom(Node *root) {
    /*
    * map(`hozirental distance from root` -> pair(node's value, node's level))
    */
   map<int, pair<int, int>> map;

   // Perform preorder traversal on the tree and fill the map
   printBottom(root, 0, 0, map);

   for(auto x: map) {
       cout << x.second.first << " ";
   }
   cout << endl;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(8);
 
    printBottom(root);
 
    return 0;
}