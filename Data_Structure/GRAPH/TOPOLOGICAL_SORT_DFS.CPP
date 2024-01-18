#include<bits/stdc++.h>
using namespace std;

void toposort(int node,unordered_map<int,bool> &visited,stack<int> &s,unordered_map<int,list<int>> &adj)
{
    visited[node] = 1;

    for(auto i : adj[node])
    {
        if(!visited[i])
        {
            toposort(i,visited,s,adj);
        }
    }

    s.push(node);
}

vector<int> topological(vector<vector<int>> &edges,int n,int m)
{
    // prepare
    unordered_map<int,list<int>> adj;
    for(int i=0;i<edges.size();i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    unordered_map<int,bool> visited;
    stack<int> s;

    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            toposort(i,visited,s,adj);
        }
    }

    vector<int> ans;

    while(!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }

    return ans;
}

int main()
{
    int n;
    cout<<"ENTER THE NUMBER OF NODES : ";
    cin>>n;

    int m;
    cout<<"ENTER THE UMBER OF EDGES : ";
    cin>>m;

    vector<vector<int>> edges(m,vector<int>(2));

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<2;j++)
        {
            cin>>edges[i][j];
        }
    }

    vector<int> ans = topological(edges,n,m);

    for(auto i : ans)
    {
        cout<<i<<" ";
    }
}