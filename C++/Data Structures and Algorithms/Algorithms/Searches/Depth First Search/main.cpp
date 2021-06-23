#include <iostream>
#include <list>

using std::cout;
using std::endl;
using std::list;

/*
Graph class represents a directed graph using adjacency list representation
*/
class Graph {
        int V; // No. of vertices

        list<int> *adj;

        // A recursive function used by DFS
        void DFSVisit(int v, bool visited[]);

    public:

        Graph(int V); // Constructor

        // Function to add an edge to graph
        void addEdge(int v, int w);

        // DFS traversal of the vertices reachable from v
        void DFS(int v);

};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
}

void Graph::DFSVisit(int v, bool visited[]) {
    // Mark the current node as visited and print it
    visited[v] = true;
    cout << v << " ";

    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); i++) {
        if(!visited[*i]) {
            DFSVisit(*i, visited);
        }
    }
}

/*
 * DFS traversal of the vertices reachable from v
 * It uses recursive DFSVisit
*/
void Graph::DFS(int v) {
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++) {
        visited[i] = false;
    }

    DFSVisit(v, visited);
}




int main(int argc, const char* argv[]) {

    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Following is Depth First Traversal"
            " (starting from vertex 2)" << endl;
    g.DFS(2);

    return 0;
}