#include<bits/stdc++.h>
using namespace std;

class graph
{
    public :

    unordered_map<int,list<int>> adj;

    void AddEdges(int u,int v,bool direction)
    {
        // directio -> 0 -> undirected graph
        // direction -> 1 -> directed graph

        adj[u].push_back(v);

        if(direction == 0)
        {
            adj[v].push_back(u);
        }
    }

    void PrintEdges()
    {
        for(auto i : adj)
        {
            cout<<"PRINTING ADJACENT LIST : ";
            cout<<i.first<<"->";

            for(auto j : i.second)
            {
                cout<<j<<" ";
            }

            cout<<endl;
        }
    }
};

int main()
{
    int n;
    cout<<"ENTER THE NUMBER OF NODES : ";
    cin>>n;

    int m;
    cout<<"ENTER THE UMBER OF EDGES : ";
    cin>>m;

    graph g;

    cout<<"ENTER THE EDGES : ";

    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;

        g.AddEdges(u,v,0);
    }

    g.PrintEdges();
}


/*#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"ENTER THE NUMBER OF NODES : ";
    cin>>n;

    int m;
    cout<<"ENTER THE UMBER OF EDGES : ";
    cin>>m;

    vector<vector<int>> ans(n,vector<int>(m,0));

    cout<<"ENTER THE EDGES : ";

    for(int i=0;i<n;i++)
    {
        int u,v;
        cin>>u>>v;

        ans[u][v] = 1;  // directed graph

        // ans[v][u] = 1; for undirected graph also
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}*/