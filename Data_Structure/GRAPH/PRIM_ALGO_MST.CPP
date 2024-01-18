#include<bits/stdc++.h>
using namespace std;

vector<int> Prim_Algo_MST(vector<vector<int>> &edges,int n,int m)
{
    // prepare adj;
    unordered_map<int,list<pair<int,int>>> adj;

    for(int i=0;i<m;i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    vector<int> key(n);
    vector<bool> mst(n);
    vector<int> parent(n);

    for(int i=0;i<n;i++)
    {
        key[i] = INT_MAX;
        parent[i] = -1;
        mst[i] = false;
    }

    // lets start algo
    key[0] = 0;
    parent[0] = -1;

    for(int i=0;i<n;i++)
    {
        int mini = INT_MAX;
        int u;
        
        // find the mini vali node

        for(int v=0;v<n;v++)
        {
            if(mst[v] == false && key[v] < mini)
            {
                u = v;
                mini = key[v];
            }
        }
            
        // mark min node as true

        mst[u] = true;

        // check its adjacent node

        for(auto i : adj[u])
        {
            int v = i.first;
            int w = i.second;

            if(mst[v] == false && w < key[v])
            {
                parent[v] = u;
                key[v] = w;
            }
        }
    }

    return parent;
}

int main()
{
    int n;
    cout<<"ENTER THE NUMBER OF NODES : ";
    cin>>n;

    int m;
    cout<<"ENTER THE NUMBER OF EDGES : ";
    cin>>m;

    vector<vector<int>> edges(m,vector<int>(3));

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>edges[i][j];
        }
    }

    vector<int> ans = Prim_Algo_MST(edges,n,m);

    for(auto i : ans)
    {
        cout<< i << " ";
    }
}

/*
0 1 2
0 3 6
1 3 8
1 4 5
1 2 3
2 4 7
*/