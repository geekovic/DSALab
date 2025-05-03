#include <iostream>
#include <vector>
#include <climits>
using namespace std;

#define MAX 100
#define INF INT_MAX

// Function to find the vertex with the minimum distance
int minDistance(vector<int>& dist, vector<bool>& visited, int V) {
    int min = INF, min_index = -1;
    for (int v = 0; v < V; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

// Dijkstra's Algorithm
void dijkstra(int graph[MAX][MAX], int V, int src) {
    vector<int> dist(V, INF);       // Distance from source to each vertex
    vector<bool> visited(V, false); // Visited vertices

    dist[src] = 0; // Distance from source to itself is 0

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited, V);
        visited[u] = true;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INF &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print the results
    cout << "Vertex\tDistance from Source (" << src << ")\n";
    for (int i = 0; i < V; i++)
        cout << i << "\t" << dist[i] << "\n";
}

int main() {
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;

    int graph[MAX][MAX];
    cout << "Enter adjacency matrix (0 for no edge):\n";
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            cin >> graph[i][j];

    int src;
    cout << "Enter source vertex (0 to " << V - 1 << "): ";
    cin >> src;

    dijkstra(graph, V, src);

    return 0;
}
