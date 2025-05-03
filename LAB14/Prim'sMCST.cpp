#include <iostream>
#include <climits>
using namespace std;

#define MAX 100
#define INF INT_MAX

int findMinKey(int key[], bool mstSet[], int V) {
    int min = INF, min_index;

    for (int v = 0; v < V; v++)
        if (!mstSet[v] && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

void printMST(int parent[], int graph[MAX][MAX], int V) {
    int cost = 0;
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << "\n";
        cost += graph[i][parent[i]];
    }
    cout << "Total cost of MST: " << cost << endl;
}

void primMST(int graph[MAX][MAX], int V) {
    int parent[MAX];  // Stores constructed MST
    int key[MAX];     // Key values used to pick minimum weight edge
    bool mstSet[MAX]; // Set of vertices included in MST

    // Initialize all keys as INFINITE
    for (int i = 0; i < V; i++)
        key[i] = INF, mstSet[i] = false;

    key[0] = 0;      // Start from first vertex
    parent[0] = -1;  // First node is root of MST

    for (int count = 0; count < V - 1; count++) {
        int u = findMinKey(key, mstSet, V);
        mstSet[u] = true;

        for (int v = 0; v < V; v++) {
            // Update key only if graph[u][v] is smaller and v is not in MST
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u, key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph, V);
}

int main() {
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;

    int graph[MAX][MAX];
    cout << "Enter adjacency matrix (0 if no edge):\n";
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            cin >> graph[i][j];

    primMST(graph, V);

    return 0;
}
