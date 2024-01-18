#include<bits/stdc++.h>
using namespace std;

void dfs(int node,int parent,vector<int> &disc,vector<int> &low,unordered_map<int,bool> &visited,unordered_map<int,list<int>> &adj,vector<int> &ap,int timer)
{
    visited[node] = true;

    low[node] = disc[node] = timer++;

    int child = 0;

    for(auto nbr : adj[node])
    {
        if(nbr == parent)
        {
            continue;
        }

        if(!visited[nbr])
        {
            // check ap or not
            dfs(nbr,node,disc,low,visited,adj,ap,timer);
            low[node] = min(low[node],low[nbr]);

            if(low[nbr] >= disc[node] && parent != -1)
            {
                ap[node] = 1;
            }

            child++;
        }

        else
        {
            // back edge
            low[node] = min(low[node],disc[nbr]);
        }
    }

    if(child > 1 && parent == -1)
    {
        ap[node] = 1;
    }
}

vector<int> Articulation(vector<vector<int>> &edges,int n,int m)
{
    // prepare adj

    unordered_map<int,list<int>> adj;

    for(int i=0;i<m;i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer = 0;
    vector<int> disc(n);
    vector<int> low(n);
    unordered_map<int,bool> visited;

    vector<int> ap(n,0);

    for(int i=0;i<n;i++)
    {
        low[i] = -1;
        disc[i] = -1;
    }

    // do bfs

    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            dfs(i,-1,disc,low,visited,adj,ap,timer);
        }
    }

    return ap;
}

int main()
{
    int n;
    cout<<"ENTER THE NUMBER OF NODES : ";
    cin>>n;

    int m;
    cout<<"ENTER THE NUMBER OF EDGES : ";
    cin>>m;

    vector<vector<int>> edges(m,vector<int>(2));

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<2;j++)
        {
            cin>>edges[i][j];
        }
    }

    vector<int> ans = Articulation(edges,n,m);

    cout<<"ARTICULATION POINT : "<<endl;

    for(int i=0;i<ans.size();i++)
    {
        if(ans[i] != 0)
        {
            cout<<i<<" ";
        }
    }
}