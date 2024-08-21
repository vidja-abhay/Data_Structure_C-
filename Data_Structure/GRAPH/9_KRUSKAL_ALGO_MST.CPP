#include<bits/stdc++.h>
using namespace std;

// Function to find the parent of a node (with path compression)
int findParent(int node, vector<int> &parent) {
    if (parent[node] == node) {
        return node;
    }
    return parent[node] = findParent(parent[node], parent);
}

// Function to perform union of two sets (union by rank)
void unionSets(int u, int v, vector<int> &parent, vector<int> &rank) {
    int rootU = findParent(u, parent);
    int rootV = findParent(v, parent);

    if (rootU != rootV) {
        if (rank[rootU] > rank[rootV]) {
            parent[rootV] = rootU;
        } else if (rank[rootU] < rank[rootV]) {
            parent[rootU] = rootV;
        } else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }
}

// Function to implement Kruskal's Algorithm
vector<vector<int>> Kruskal_Algo_MST(int n, vector<vector<int>> &edges) {
    // Sort the edges based on their weight
    sort(edges.begin(), edges.end(), [](const vector<int> &a, const vector<int> &b) {
        return a[2] < b[2];
    });

    vector<int> parent(n);
    vector<int> rank(n, 0);

    // Initialize parent array (each node is its own parent initially)
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    vector<vector<int>> mst;

    // Kruskal's Algorithm to find MST
    for (const auto &edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int weight = edge[2];

        // Check if the current edge forms a cycle
        if (findParent(u, parent) != findParent(v, parent)) {
            mst.push_back({u, v, weight});
            unionSets(u, v, parent, rank);
        }
    }

    return mst;
}

int main() {
    int n, m;
    cout << "ENTER THE NUMBER OF NODES: ";
    cin >> n;
    cout << "ENTER THE NUMBER OF EDGES: ";
    cin >> m;

    vector<vector<int>> edges(m, vector<int>(3));

    cout << "ENTER THE EDGES (u v w):" << endl;
    for (int i = 0; i < m; i++) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    vector<vector<int>> mst = Kruskal_Algo_MST(n, edges);

    cout << "MINIMUM SPANNING TREE EDGES AND THEIR WEIGHTS:" << endl;
    for (const auto &edge : mst) {
        cout << edge[0] << " - " << edge[1] << " : " << edge[2] << endl;
    }

    return 0;
}

/*
Sample Input:
ENTER THE NUMBER OF NODES : 5
ENTER THE NUMBER OF EDGES : 7
0 1 2
0 3 6
1 3 8
1 4 5
1 2 3
2 4 7
3 4 9

Expected Output:
MINIMUM SPANNING TREE EDGES AND THEIR WEIGHTS:
0 - 1 : 2
1 - 2 : 3
1 - 4 : 5
0 - 3 : 6
*/
