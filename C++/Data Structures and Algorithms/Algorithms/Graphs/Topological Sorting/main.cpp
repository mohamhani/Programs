#include <iostream> 
#include <list> 
#include <stack>

using std::cout;
using std::endl;
using std::list;
using std::stack;

class Graph {
    // No. of vertices
    int V;

    list<int> *adj;

    void topologicalSortUtil(int v, bool visited[], stack<int> &Stack);

    public:
        Graph(int V);

        void addEdge(int v, int w);

        void topologicalSort();
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
}

void Graph::topologicalSortUtil(int v, bool visited[], stack<int> &Stack) {
    visited[v] = true;

    list<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); i++) {
        if(!visited[*i]) {
            topologicalSortUtil(*i, visited, Stack);
        }
    }

    Stack.push(v);
}

void Graph::topologicalSort() {
    stack<int> Stack;

    bool *visited = new bool[V];
    for(int i = 0; i < V; i++) {
        visited[i] = false;
    }

    for(int i = 0; i < V; i++) {
        if(visited[i] == false) {
            topologicalSortUtil(i, visited, Stack);
        }
    }

    while(Stack.empty() == false) {
        cout << Stack.top() << " ";
        Stack.pop();
    }
    cout << endl;
}


int main(int argc, const char* argv[]) {

    // Create a graph given in the above diagram 
    Graph graph(6); 
    graph.addEdge(5, 2); 
    graph.addEdge(5, 0); 
    graph.addEdge(4, 0); 
    graph.addEdge(4, 1); 
    graph.addEdge(2, 3); 
    graph.addEdge(3, 1); 
  
    cout << "Following is a Topological Sort of the given "
            "graph \n"; 
    
    // Function Call 
    graph.topologicalSort(); 

    return 0;
}