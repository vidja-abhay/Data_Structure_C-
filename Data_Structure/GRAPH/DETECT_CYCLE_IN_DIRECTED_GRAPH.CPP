#include<bits/stdc++.h>
using namespace std;

bool cycledetect(int node,unordered_map<int,bool> &visited,unordered_map<int,bool> &dfsvisited,unordered_map<int,list<int>> &adj)
{
    visited[node] = true;
    dfsvisited[node] = true;

    for(auto i : adj[node])
    {
        if(!visited[i])
        {
            bool check = cycledetect(i,visited,dfsvisited,adj);

            if(check)
            {
                return true;
            }
        }

        else if(dfsvisited[i])
        {
            return true;
        }
    }

    dfsvisited[node] = false;
    return false;
}

string iscycle(int n,vector<pair<int,int>> & edges)
{
    // prepare adjancecy list
    unordered_map<int,list<int>> adj;

    for(int i=0;i<edges.size();i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
    }

    unordered_map<int,bool> visited;
    unordered_map<int,bool> dfsvisited;

    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            bool ans = cycledetect(i,visited,dfsvisited,adj);

            if(ans)
            {
                return "YES";
            }
        }
    }

    return "NO";
}

string cyclebfs(vector<pair<int,int>> & edges,int n,int m)
{
    unordered_map<int,list<int>> adj;

    // prepare
    for(int i=0;i<m;i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
    }

    // find all indegree          

    vector<int> indegree(n);

    for(auto i : adj)
    {
        for(auto j : i.second)
        {
            indegree[j]++;
        }
    }

    // 0 degree valo ko push karo

    queue<int> q;
    
    for(int i=1;i<=n;i++)
    {
        if(indegree[i] == 0)
        {
            q.push(i);
        }
    }

    // do bfs

    int count=0;

    while(!q.empty())
    {
        int front = q.front();
        q.pop();

        // ans store

        count++;

        // neighbour indegree update

        for(auto i : adj[front])
        {
            indegree[i]--;

            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }
    }

    if(count == n)
    {
        return "NO";
    }
    else
    {
        return "YES";
    }
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

    string ans = iscycle(n,edges);
    cout<<ans<<endl;

    string res = cyclebfs(edges,n,m);
    cout<<res<<endl;
}