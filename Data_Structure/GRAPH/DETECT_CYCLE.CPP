#include<bits/stdc++.h>
using namespace std;

bool iscyclebfs(int src,unordered_map<int,bool> &visited,unordered_map<int,list<int>> &adj)
{
    unordered_map<int,int> parent;

    parent[src] = -1;
    visited[src] = 1;
    queue<int> q;
    q.push(src);

    while(!q.empty())
    {
        int front = q.front();
        q.pop();

        for(auto i : adj[front])
        {
            if(visited[i] == 1 && i != parent[front])
            {
                return true;
            }

            else if(!visited[i])
            {
                q.push(i);
                visited[i] = 1;
                parent[i] = front;
            }
        }
    }

    return false;
}

bool iscycledfs(int node,int parent,unordered_map<int,list<int>> adj,unordered_map<int,bool> visited)
{
    visited[node] = true;

    for(auto i : adj[node])
    {
        if(!visited[i])
        {
            bool iscycle = iscycledfs(i,node,adj,visited);

            if(iscycle)
            {
                return true;
            }
        }

        else if(i != parent)
        {
            return true;
        }
    }

    return false;
}

string cycle(vector<vector<int>> &edges,int n,int m)
{
    // prepare adjacency list
    unordered_map<int,list<int>> adj;

    for(int i=0;i<edges.size();i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int,bool> visited;

    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            //bool ans = iscyclebfs(i,visited,adj);

            bool ans = iscycledfs(i,-1,adj,visited);

            if(ans == 1)
            {
                return "Yes";
            }
        }
    }

    return "No";
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

    string ans = cycle(edges,n,m);

    cout<<ans;
}