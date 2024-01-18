#include<bits/stdc++.h>
using namespace std;

int bellman(int n,int m,int src,int dest,vector<vector<int>> &edges)
{
    vector<int> dist(n,1e9);
    dist[src] = 0;

    // n-1 times

    for(int i=0;i<n-1;i++)        // node start always 0
    {
        // travese on edge list

        for(int j=0;j<m;j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];

            if(dist[u] != 1e9 && (dist[u] + wt) < dist[v])
            {
                dist[v] = dist[u] + wt;
            }
        }
    }

    // check -ve cycle

    bool flag = 0;
    for(int j=0;j<m;j++)
    {
        int u = edges[j][0];
        int v = edges[j][1];
        int wt = edges[j][2];

        if(dist[u] != 1e9 && (dist[u] + wt) < dist[v])
        {
            flag = 1;
        }
    }

    if(flag == 0)
    {
        return dist[dest];
    }
    else
    {
        return -1;
    }
}

int main()
{
    int n;
    cout<<"ENTER THE NUMBER OF NODES : ";
    cin>>n;

    int m;
    cout<<"ENTER THE NUMBER OF EDGES : ";
    cin>>m;

    vector<vector<int>> edges(m,vector<int>(3));

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>edges[i][j];
        }
    }

    int src;
    cout<<"ENTER THE SOURCE NODE : ";
    cin>>src;

    int dest;
    cout<<"ENTER THE DESTINATION NODE : ";
    cin>>dest;

    cout<<bellman(n,m,src,dest,edges);
}