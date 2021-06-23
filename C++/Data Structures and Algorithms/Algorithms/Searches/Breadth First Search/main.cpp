#include <iostream>
#include <list>

using std::cout;
using std::endl;
using std::list;

class Graph {
    int V; // No. of vertices

    //An array containing pointers to a linked list
    list<int> *adj;

    public:
        Graph(int V);

        // Function to add an edge to graph
        void addEdge(int v, int w);

        // Prints BFS traversal from a given source startEdge
        void BFS(int startEdge);
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int vertex, int newVertex) {
    adj[vertex].push_back(newVertex);
}

void Graph::BFS(int startVertex) {
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++) {
        visited[i] = false;
    }

    // Create a queue for BFS
    list<int> queue;

    //Mark the current vertex as visited and enqueue
    visited[startVertex] = true;
    queue.push_back(startVertex);

    // 'i' will be used to get all adjacent vertices for a vertex
    list<int>::iterator i; 

    while(!queue.empty()) {
        // Dequeue a vertex from queue and print
        int s = queue.front();
        cout << s << " ";
        queue.pop_front();

        // Get all adjacent vertices of the dequeued vertex s. If an adjacent has not been visited, then mark it visited and enqueue it
        for(i = adj[s].begin(); i != adj[s].end(); i++) {
            if(!visited[*i]) {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}


int main(int argc, const char* argv[]) {

    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3);

    g.BFS(2);

    return 0;
}