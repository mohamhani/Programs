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

void printTop(Node *node, int dist, int level, map<int, pair<int, int>> &map) {
    if(node == nullptr) {
        return;
    }

    /*
    * If the current level is less than the maximum
    * level seen so far for the same horizontal distance,
    * or if the horizontal distance is seen for the
    * first time, update the map
    */
    if(map.find(dist) == map.end() || level < map[dist].second) {
        map[dist] = {node->data, level};
    }

    /*
    * Recursive for the left subtree by decreasing
    * hozizontal distance and increasing level by one
    */
    printTop(node->left, dist - 1, level + 1, map);

    /*
    * Recursive for the left subtree by increasing both
    * hozizontal distance and level by one
    */
    printTop(node->right, dist + 1, level + 1, map);
}

void printTop(Node *root) {
    /*
    * map(`hozirental distance from root` -> pair(node's value, node's level))
    */
   map<int, pair<int, int>> map;

   // Perform preorder traversal on the tree and fill the map
   printTop(root, 0, 0, map);

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
 
    printTop(root);
 
    return 0;
}