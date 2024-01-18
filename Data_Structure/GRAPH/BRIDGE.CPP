#include<bits/stdc++.h>
using namespace std;

void dfs(int node,int parent,int timer,vector<int> &disc,vector<int> &low,vector<vector<int>> &result,unordered_map<int,list<int>> &adj,unordered_map<int,bool> &visited)
{
    visited[node] = true;

    disc[node] = low[node] = timer++;

    for(auto nbr : adj[node])
    {
        if(nbr == parent)
        {
            continue;
        }

        if(!visited[nbr])
        {
            dfs(nbr,node,timer,disc,low,result,adj,visited);

            low[node] = min(low[node],low[nbr]);

            // check edge is bridge

            if(low[nbr] > disc[node])
            {
                vector<int> ans;
                ans.push_back(node);
                ans.push_back(nbr);

                result.push_back(ans);
            }
        }

        else
        {
            // back edge

            low[node] = min(low[node],disc[nbr]);
        }
    }
}

vector<vector<int>> birdge(vector<vector<int>> &edges,int n,int m)
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
    int parent = -1;
    unordered_map<int,bool> visited;

    for(int i=0;i<n;i++)
    {
        disc[i] = -1;
        low[i] = -1;
    }

    // do bfs

    vector<vector<int>> result;

    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            dfs(i,parent,timer,disc,low,result,adj,visited);
        }
    }

    return result;
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

    vector<vector<int>> ans = birdge(edges,n,m);

    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }

        cout<<endl;
    }
}