#include <iostream> 
#include <limits>

using std::cout;
using std::endl;
using std::numeric_limits;

#define V 9

/**
 * A utility function to find the vertex with minimum distance
 * value from the set of vertices not yet included in shortest path tree
*/
int minDistance(int dist[], bool sptSet[]) {
    int min = numeric_limits<int>::max(), min_index;

    for(int v = 0; v < V; v++) {
        if(sptSet[v] == false && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

void printSolution(int dist[]) {
    cout << "Vertex \t\t Distance from Source" << endl;
    for(int i = 0; i < V; i++) {
        cout << i << "\t\t\t" << dist[i] << endl;
    }
}

void dijkstra(int graph[V][V], int src) {
    int dist[V]; // dist[i] will hold the shortest distance from src to i

    /**
     * sptSet[i] will be true if vertex i is included in shortest
     * path tree or shortest distance from src to i is finalized
    */
    bool sptSet[V];

    // Initialize all distances as INFINITE and sptSet[] as false
    for(int i = 0; i < V; i++) {
        dist[i] = numeric_limits<int>::max();
        sptSet[i] = false;
    }

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for(int count = 0; count < V - 1; count++) {
        /**
         * Pick the minimum distance vertex from the set of vertices
         * not yet processed. u is always equal to src in the first iteration 
        */
       int u = minDistance(dist, sptSet);
       cout << u << endl;

       // Mark the picked vertex as processed
       sptSet[u] = true;

       // Update dist value of the adjacent vertices of the picked vertex
       for(int v = 0; v < V; v++) {
           /**
            * Update dist[v] only if it's not in sptSet, there is an edge from
            * u to v and the total weight from src to v through u is smaller than the 
            * current value of dist[V]
           */
           if(!sptSet[v] && graph[u][v] && dist[u] != numeric_limits<int>::max() && dist[u] + graph[u][v] < dist[v]) {
               dist[v] = dist[u] + graph[u][v];
               //cout << dist[v] << " ";
           }
       }
       //cout << endl;
    }

    printSolution(dist);
}

int main() 
{ 
    /* Let us create the example graph discussed above */
    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } }; 

    dijkstra(graph, 0);
  
    return 0; 
} 

