#include<bits/stdc++.h>
using namespace std;

void prepareadjlist(unordered_map<int,set<int>> adjlist,vector<pair<int,int>> &edges)
{
    for(int i=0;i<edges.size();i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adjlist[u].insert(v);
        adjlist[v].insert(u);
    }
}

void bfs(unordered_map<int,set<int>> &adjlist,unordered_map<int,bool> &visited,vector<int> &ans,int node)
{
    queue<int> q;
    q.push(node);
    visited[node] = 1;

    while(!q.empty())
    {
        int frontnode = q.front();
        q.pop();

        // store frontnoe in ans
        ans.push_back(frontnode);

        // travese all neighber

        for(auto i : adjlist[frontnode])
        {
            if(!visited[i])
            {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

vector<int> BFS(int n,vector<pair<int,int>> &edges)
{
    unordered_map<int,set<int>> adjlist;         // set ni jagya ye list hale
    vector<int> ans;
    unordered_map<int,bool> visited;

    prepareadjlist(adjlist,edges);

    // travesal all component of graph

    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            bfs(adjlist,visited,ans,i);
        }
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

    vector<pair<int,int>> edges;

    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;

        pair<int,int> ans = make_pair(u,v);

        edges.push_back(ans);
    }

    vector<int> ans = BFS(n,edges);

    for(auto i : ans)
    {
        cout<< i <<" ";
    }
}