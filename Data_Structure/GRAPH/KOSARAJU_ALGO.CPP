// COUNT STRONGLY CONNECTED COMPONENTS

#include<bits/stdc++.h>
using namespace std;

void dfs(int node,unordered_map<int,bool> &visited,stack<int> &s,unordered_map<int,list<int>> &adj)
{
    visited[node] = true;

    for(auto i : adj[node])
    {
        if(!visited[i])
        {
            dfs(i,visited,s,adj);
        }
    }

    s.push(node);
}

void DFS(int node,unordered_map<int,bool> &visited,unordered_map<int,list<int>> &transpose)
{
    visited[node] = true;

    for(auto nbr : transpose[node])
    {
        if(!visited[nbr])
        {
            DFS(nbr,visited,transpose);
        }
    }
}

int kosaraju(vector<vector<int>> &edges,int n,int m)
{
    // prepare adj

    unordered_map<int,list<int>> adj;

    for(int i=0;i<m;i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    // topological sort

    stack<int> s;
    unordered_map<int,bool> visited;

    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            dfs(i,visited,s,adj);
        }
    }

    // create a tranpose graph
    unordered_map<int,list<int>> transpose;

    for(int i=0;i<n;i++)
    {
        visited[i] = 0;
        for(auto nbr : adj[i])
        {
            transpose[nbr].push_back(i);
        }
    }

    // dfs call using above ordering
    int count = 0;
    while(!s.empty())
    {
        int top = s.top();
        s.pop();

        if(!visited[top])
        {
            count++;
            DFS(top,visited,transpose);
        }
    }

    return count;
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

    cout<<kosaraju(edges,n,m);
}