#include<bits/stdc++.h>
using namespace std;

vector<int> shortestPath(vector<vector<int>> &edges,int n,int m,int s,int d)
{
    unordered_map<int,list<int>> adj;

    // prepare

    for(int i=0;i<edges.size();i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // do bfs
    
    unordered_map<int,bool> visited;
    unordered_map<int,int> parent;
    queue<int> q;

    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while(!q.empty())
    {
        int front = q.front();
        q.pop();

        for(auto i : adj[front])
        {
            if(!visited[i])
            {
                visited[i] = true;
                parent[i] = front;
                q.push(i);
            }
        }
    }

    // prepare shortest path

    vector<int> ans;

    int current = d;
    ans.push_back(d);

    while(current != s)
    {
        current = parent[current];
        ans.push_back(current);
    }

    reverse(ans.begin(),ans.end());

    return ans;
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

    vector<int> ans = shortestPath(edges,n,m,1,7);

    for(auto i : ans)
    {
        cout<<i<<" ";
    }
}