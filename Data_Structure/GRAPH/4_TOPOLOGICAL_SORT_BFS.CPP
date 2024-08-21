#include <bits/stdc++.h>
using namespace std;

vector<int> topological(vector<vector<int>> &edges, int n, int m) {
    unordered_map<int, list<int>> adj;

    // Prepare the adjacency list
    for (int i = 0; i < m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }

    // Initialize all indegree values to 0
    vector<int> indegree(n, 0);

    // Calculate in-degrees for each node
    for (auto i : adj) {
        for (auto j : i.second) {
            indegree[j]++;
        }
    }

    // Push nodes with 0 indegree into the queue
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    // Perform BFS and store the topological order
    vector<int> ans;
    while (!q.empty()) {
        int front = q.front();
        q.pop();

        // Store the node in the topological order
        ans.push_back(front);

        // Update the in-degrees of adjacent nodes
        for (auto i : adj[front]) {
            indegree[i]--;

            if (indegree[i] == 0) {
                q.push(i);
            }
        }
    }

    return ans;
}

int main() {
    int n;
    cout << "ENTER THE NUMBER OF NODES: ";
    cin >> n;

    int m;
    cout << "ENTER THE NUMBER OF EDGES: ";
    cin >> m;

    vector<vector<int>> edges(m, vector<int>(2));

    cout << "ENTER THE EDGES (u v):" << endl;
    for (int i = 0; i < m; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }

    vector<int> ans = topological(edges, n, m);

    cout << "TOPOLOGICAL SORT: ";
    for (auto i : ans) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
