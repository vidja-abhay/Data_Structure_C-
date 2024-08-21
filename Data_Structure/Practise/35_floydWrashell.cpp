#include <bits/stdc++.h>
using namespace std;

// Define infinity as a large enough number. This represents no connection between nodes.
#define INF 1e9

void floydWarshall(vector<vector<int>> &graph, int V) {
    // Create a distance matrix initialized with the graph's adjacency matrix.
    vector<vector<int>> dist = graph;

    // Floyd-Warshall Algorithm
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                // Update dist[i][j] if a shorter path is found via vertex k.
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    // Print the shortest distance matrix.
    cout << "The following matrix shows the shortest distances between every pair of vertices:" << endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                cout << "INF" << "\t";
            else
                cout << dist[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    int V; // Number of vertices in the graph
    cout << "Enter the number of vertices: ";
    cin >> V;

    // Initialize graph with all edges as INF initially (except diagonal as 0)
    vector<vector<int>> graph(V, vector<int>(V, INF));

    // Input the graph
    cout << "Enter the adjacency matrix (use " << INF << " for no direct connection):\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
            if (i == j) graph[i][j] = 0; // Distance to self is zero
        }
    }

    // Run Floyd-Warshall algorithm
    floydWarshall(graph, V);

    return 0;
}
