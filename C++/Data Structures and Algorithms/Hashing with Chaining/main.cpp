#include <iostream>
#include <list>

using std::cout;
using std::endl;
using std::list;

class Hash {
    int BUCKET;

    // Pointer to an array containing buckets
    list <int> *table;

    public:
        Hash(int V); // Constructor

        void inserItem(int x);
        void deleteItem(int key);

        int hashFunction(int x) {
            return (x % BUCKET);
        }

        void displayHash();
};

Hash::Hash(int b) {
    BUCKET = b;

    table = new list<int>[BUCKET];
}

void Hash::inserItem(int x) {
    int index = hashFunction(x);
    table[index].push_back(x);
}

void Hash::deleteItem(int key) {
    int index = hashFunction(key);

    list <int> :: iterator i;
    for(i = table[index].begin(); i != table[index].end(); i++) {
        if(*i == key) {
            break;
        }
    }

    if(i != table[index].end()) {
        table[index].erase(i);
    }
}

void Hash::displayHash() {
    cout << endl;
    for(int i = 0; i < BUCKET; i++) {
        cout << i;
        for(auto x : table[i]) {
            cout << "-->" << x;
        }
        cout << endl;
    }
    cout << endl;
}

int main(int argc, const char* argv[]) {
    int a[] = {15, 11, 27, 8, 12};
    int n = sizeof(a)/sizeof(a[0]);

    Hash h(7);

    for(int i = 0; i < n; i++) {
        h.inserItem(a[i]);
    }

    h.displayHash();

    h.deleteItem(12);

    h.displayHash();

    return 0;
}

