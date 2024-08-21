//ANS IN 1-D VECTOR

#include<bits/stdc++.h>
using namespace std;

void dfs(int node,unordered_map<int,bool> &visited,unordered_map<int,list<int>> &adj,vector<int> &component)
{
    component.push_back(node);
    visited[node] = true;

    for(auto i : adj[node])
    {
        if(!visited[i])
        {
            dfs(i,visited,adj,component);
        }
    }
}

vector<int> DFS(int n,vector<vector<int>> &edges)
{
    unordered_map<int,list<int>> adj;

    // prepare adjlist

    for(int i=0;i<edges.size();i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int,bool> visited;
    vector<int> ans;

    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            
            dfs(i,visited,adj,ans);
           
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

    vector<vector<int>> edges(m,vector<int>(2));

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<2;j++)
        {
            cin>>edges[i][j];
        }
    }

    vector<int> ans = DFS(n,edges);

    for(auto i : ans)
    {
        cout<< i <<" ";
    }
}


/*ANS IN 2-D VECTOR(CODE STUDIO MUJAB)

#include<bits/stdc++.h>
using namespace std;

void dfs(int node,unordered_map<int,bool> &visited,unordered_map<int,list<int>> &adj,vector<int> &component)
{
    component.push_back(node);
    visited[node] = true;

    for(auto i : adj[node])
    {
        if(!visited[i])
        {
            dfs(i,visited,adj,component);
        }
    }
}

vector<vector<int>> DFS(int n,vector<vector<int>> &edges)
{
    unordered_map<int,list<int>> adj;

    // prepare adjlist

    for(int i=0;i<edges.size();i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int,bool> visited;
    vector<vector<int>> ans;

    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            vector<int> component;
            dfs(i,visited,adj,component);
            ans.push_back(component);
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

    vector<vector<int>> edges(m,vector<int>(2));

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<2;j++)
        {
            cin>>edges[i][j];
        }
    }

    vector<vector<int>> ans = DFS(n,edges);

    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }

        cout<<endl;
    }
    
}*/