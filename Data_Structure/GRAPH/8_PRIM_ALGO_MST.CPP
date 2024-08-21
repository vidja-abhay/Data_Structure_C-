#include<bits/stdc++.h>
using namespace std;

vector<pair<pair<int, int>, int>> Prim_Algo_MST(vector<vector<int>>& edges, int n, int m) {
    // Prepare the adjacency list
    unordered_map<int, list<pair<int, int>>> adj;

    for (int i = 0; i < m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    vector<int> key(n);
    vector<bool> mst(n);
    vector<int> parent(n);

    // Initialize key, parent, and mst arrays
    for (int i = 0; i < n; i++) {
        key[i] = INT_MAX;
        parent[i] = -1;
        mst[i] = false;
    }

    // Let's start the algorithm
    key[0] = 0;
    parent[0] = -1;

    for (int i = 0; i < n - 1; i++) {
        int mini = INT_MAX;
        int u = -1;

        // Find the minimum value node
        for (int v = 0; v < n; v++) {
            if (!mst[v] && key[v] < mini) {
                u = v;
                mini = key[v];
            }
        }

        // Mark min node as true
        mst[u] = true;

        // Check its adjacent nodes
        for (auto it : adj[u]) {
            int v = it.first;
            int w = it.second;

            if (!mst[v] && w < key[v]) {
                parent[v] = u;
                key[v] = w;
            }
        }
    }

    // Collect the result
    vector<pair<pair<int, int>, int>> result;

    for (int i = 1; i < n; i++) {
        result.push_back({ {parent[i], i}, key[i] });
    }

    return result;
}

int main() {
    int n;
    cout << "ENTER THE NUMBER OF NODES : ";
    cin >> n;

    int m;
    cout << "ENTER THE NUMBER OF EDGES : ";
    cin >> m;

    vector<vector<int>> edges(m, vector<int>(3));

    cout << "ENTER THE EDGES (u v w):" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> edges[i][j];
        }
    }

    vector<pair<pair<int, int>, int>> ans = Prim_Algo_MST(edges, n, m);
    
    int totalWeight = 0;

    cout << "MINIMUM SPANNING TREE EDGES AND THEIR WEIGHTS:" << endl;
    for (auto edge : ans) {
        cout << edge.first.first << " - " << edge.first.second << " : " << edge.second << endl;
        
        totalWeight += edge.second;
    }
    
    cout<<"Total Weight : "<<totalWeight<<endl;
    
    

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
