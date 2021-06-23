#include <iostream>
#include <list>
#include <utility>
#include <limits>
#include <queue>
#include <vector>
#include <functional>

using std::cout;
using std::endl;
using std::list;
using std::pair;
using std::make_pair;
using std::numeric_limits;
using std::priority_queue;
using std::greater;
using std::vector;

#define INF 0x3f3f3f3f

typedef pair<int, int> iPair;

class Graph {
    // No. of vertices
    int V; 

    /**
     * In a weighted graph, we need to store vertex
     * and weight pair for every edge
    */
    list<pair<int, int>> *adj;

    public:
        Graph(int V);
        void addEdge(int u, int v, int w);
        void shortestPath(int s);
        void printSolution(vector<int> &dist);
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<iPair>[V];
}

void Graph::addEdge(int u, int v, int w) {
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

void Graph::printSolution(vector<int> &dist) {
    int x = 0;
    cout << "Vertex \t\t Distance from Source" << endl;
    for(int i : dist) {
        cout << x << "\t\t\t" << i << endl;
        x++;
    }
}

void Graph::shortestPath(int src) {
    /**
     * Create a priority queue to store vertices that are
     * being processed.
    */
    priority_queue<iPair, vector <iPair>, greater<iPair>> pq;

    /**
     * Create a vector for distances and initialize all distances as infinite (INF)
    */
    vector<int> dist(V, INF);

    /**
     * Insert source itself in priority queue and initialize
     * its distance as 0. Note the first of the pair is the distance, and the second
     * is the vertex. It has to be stored this way to keep the vertices sorted
     * by distance (distance must be first item in pair)
     */
    pq.push(make_pair(0, src));
    dist[src] = 0;

    /**
     * Looping till priority queue becomes empty (or
     * all distances are not finalized)
     */
    while(!pq.empty()) {
        /**
         * The first vertex in pair is the minimum distance 
         * vertex, extract it from priority queue.
         */
        int u = pq.top().second;
        pq.pop();

        list<pair<int, int>>::iterator i;
        for(i = adj[u].begin(); i != adj[u].end(); i++) {
            /**
             * Get vertex label and weight of current adjacent of u
             */
            int v = (*i).first;
            int weight = (*i).second;

            // If there is a shorter path to v through u
            if(dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }

    }

    printSolution(dist);

}

int main() {
    int V = 9;

    Graph graph(V);

    /***
     * [0]: u
     * [1]: v
     * [2] : distance between u and v AKA distance between two vertices
    */
    graph.addEdge(0, 1, 4); 
    graph.addEdge(0, 7, 8); 
    graph.addEdge(1, 2, 8); 
    graph.addEdge(1, 7, 11); 
    graph.addEdge(2, 3, 7); 
    graph.addEdge(2, 8, 2); 
    graph.addEdge(2, 5, 4); 
    graph.addEdge(3, 4, 9); 
    graph.addEdge(3, 5, 14); 
    graph.addEdge(4, 5, 10); 
    graph.addEdge(5, 6, 2); 
    graph.addEdge(6, 7, 1); 
    graph.addEdge(6, 8, 6); 
    graph.addEdge(7, 8, 7); 
  
    graph.shortestPath(0);


}