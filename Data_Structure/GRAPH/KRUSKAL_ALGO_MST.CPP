#include<bits/stdc++.h>
using namespace std;

bool cmp(vector<int> &a,vector<int> &b)
{
    return a[2] < b[2];
}

void MakeSet(vector<int> &parent,vector<int> &rank,int n)
{
    for(int i=0;i<n;i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}

int FindParent(vector<int> &parent,int node)
{
    if(parent[node] == node)
    {
        return node;
    }

    return parent[node] = FindParent(parent,parent[node]);
}

void UnionSt(int u,int v,vector<int> &parent,vector<int> &rank)
{
    u = FindParent(parent,u);
    v = FindParent(parent,v);

    if(rank[u] < rank[v])
    {
        parent[u] = v;
    }

    else if(rank[u] > rank[v])
    {
        parent[v] = u;
    }

    else
    {
        parent[v] = u;
        rank[u]++;
    }
}

int Kruskal_Algo(vector<vector<int>> &edges,int n)
{
    sort(edges.begin(),edges.end(),cmp);       // sort by weight

    vector<int> parent(n);
    vector<int> rank(n);

    MakeSet(parent,rank,n);
    int wt = 0;

    for(int i=0;i<edges.size();i++)
    {
        int u = FindParent(parent,edges[i][0]);
        int v = FindParent(parent,edges[i][1]);
        int w = edges[i][2];

        if(u != v)
        {
            wt += w;
            UnionSt(u,v,parent,rank);
        }
    }

    // for(auto i : parent)
    // {
    //     cout<<i<<" ";
    // }
    // cout<<endl;

    return wt;
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

    /*vector<int> ans = Kruskal_Algo(edges,n);

    for(auto i : ans)
    {
        cout<<i<<" ";
    }*/

    cout<<Kruskal_Algo(edges,n);

    return 0;
}

// MST MEANS = MINIMUM SPANNING TREE