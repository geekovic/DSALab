#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int src, dest, weight;
};

bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

class DisjointSet {
    vector<int> parent, rank;

public:
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i, rank[i] = 0;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]); // Path compression
        return parent[x];
    }

    void unite(int x, int y) {
        int xr = find(x);
        int yr = find(y);
        if (xr == yr)
            return;

        // Union by rank
        if (rank[xr] < rank[yr])
            parent[xr] = yr;
        else if (rank[xr] > rank[yr])
            parent[yr] = xr;
        else {
            parent[yr] = xr;
            rank[xr]++;
        }
    }
};

void kruskalMST(vector<Edge>& edges, int V) {
    sort(edges.begin(), edges.end(), compare);

    DisjointSet ds(V);
    vector<Edge> result;
    int mst_cost = 0;

    for (Edge e : edges) {
        int set_u = ds.find(e.src);
        int set_v = ds.find(e.dest);

        if (set_u != set_v) {
            result.push_back(e);
            mst_cost += e.weight;
            ds.unite(set_u, set_v);
        }
    }

    cout << "\nEdges in the Minimum Spanning Tree:\n";
    for (Edge e : result)
        cout << e.src << " - " << e.dest << " : " << e.weight << endl;

    cout << "Total cost of MST: " << mst_cost << endl;
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<Edge> edges(E);
    cout << "Enter edges in format (src dest weight):\n";
    for (int i = 0; i < E; i++)
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;

    kruskalMST(edges, V);

    return 0;
}
