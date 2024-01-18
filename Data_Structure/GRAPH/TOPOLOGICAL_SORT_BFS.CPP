#include<bits/stdc++.h>
using namespace std;

vector<int> topological(vector<vector<int>> &edges,int n,int m)
{
    unordered_map<int,list<int>> adj;

    // prepare
    for(int i=0;i<m;i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    // find all indegree          // first node alwas 0

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
    
    for(int i=0;i<n;i++)
    {
        if(indegree[i] == 0)
        {
            q.push(i);
        }
    }

    // do bfs

    vector<int> ans;

    while(!q.empty())
    {
        int front = q.front();
        q.pop();

        // ans store

        ans.push_back(front);

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

    vector<int> ans = topological(edges,n,m);

    for(auto i : ans)
    {
        cout<< i <<" ";
    }
}