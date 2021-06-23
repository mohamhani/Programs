#include <iostream>
#include <limits>

/**
* Bellman-Ford Algorithm implementation
**/

using std::cout;
using std::endl;
using std::numeric_limits;

struct Edge {
    int src, dest, weight;
};

struct Graph {
    /**
     * V -> Number of vertices
     * E -> Number of edges
    */
    int V, E;

    /**
     * Graph is represented as an array of edges
     */
    struct Edge *edge;
};

// Creates a graph with V vertices and E edges
struct Graph* createGraph(int V, int E) {
    struct Graph *graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[E];
    
    return graph;
}

void printSolution(int dist[], int n) {
    cout << "Vertex \t\t Distance from Source" << endl;
    for(int i = 0; i < n; i++) {
        cout << i << "\t\t\t" << dist[i] << endl;
    }
}

void BellmanFord(struct Graph *graph, int src) {
    int V = graph->V;
    int E = graph->E;
    int dist[V];

    /**
     * Initialize distances from src to all
     * other vertices as INFINITE
    */
    for(int i = 0; i < V; i++) {
        dist[i] = numeric_limits<int>::max();
    }

    dist[src] = 0;

    /***
     * Relax all edges |V| -1 times. A simple shortest
     * path from src to any other vertex can have at-most
     * |V| - 1  edges. 
    */
    for(int i = 1; i <= V - 1; i++) {
        for(int j = 0; j < E; j++) {
            int u = graph->edge[j].src;
            int v = graph->edge[j].dest;
            int weight = graph->edge[j].weight;
            if(dist[u] != numeric_limits<int>::max() && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    /**
     * Check for negative-weight cycles. The above step
     * guarantees shortest distance if graph doesn't contain
     * negative weight cycle. If we get a shorter path, then there
     * is a negative cycle
     */
    for(int i = 0; i < E; i++) {
        int u = graph->edge[i].src;
        int v = graph->edge[i].dest;
        int weight = graph->edge[i].weight;
        if(dist[u] != numeric_limits<int>::max() && dist[u] + weight < dist[v]) {
            cout << "Graph contains a negative weight cycle" << endl;
            return;
        }
    }

    printSolution(dist, V);

    return;
}

int main() {
    int V = 5; // Number of vertices in graph
    int E = 8; // Number of edges in graph

    struct Graph *graph = createGraph(V, E);

    // Add edge 0-1
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = -1;

    // Add edge 0-2
    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 4;

    // Add edge 1-2
    graph->edge[2].src = 1;
    graph->edge[2].dest = 2;
    graph->edge[2].weight = 3;

    // Add edge 1-3
    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 2;

    // Add edge 1-4
    graph->edge[4].src = 1;
    graph->edge[4].dest = 4;
    graph->edge[4].weight = 2;

    // Add edge 3-1
    graph->edge[5].src = 3;
    graph->edge[5].dest = 1;
    graph->edge[5].weight = 1;

    // Add edge 3-2
    graph->edge[6].src = 3;
    graph->edge[6].dest = 2;
    graph->edge[6].weight = 5;

    // Add edge 4-3
    graph->edge[7].src = 4;
    graph->edge[7].dest = 3;
    graph->edge[7].weight = -3;

    BellmanFord(graph, 0);

    return 0;
}

