#include<bits/stdc++.h>
using namespace std;

vector<int> s_path_dijkstra( vector<vector<int>> &edges,int n,int m,int src)
{
    // prepare adj

    unordered_map<int,list<pair<int,int>>> adj;

    for(int i=0;i<m;i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    // create distace vector & initilize int_max

    vector<int> dist(n);

    for(int i=0;i<n;i++)
    {
        dist[i] = INT_MAX;
    }

    // creat a set (distance,node)

    set<pair<int,int>> st;

    dist[src] = 0;
    st.insert(make_pair(0,src));

    while(!st.empty())
    {
        // fetch top record

        auto top = *(st.begin());

        int node_dist = top.first;
        int node = top.second;

        // remove top record

        st.erase(st.begin());

        // travese on neighbour

        for(auto i : adj[node])
        {
            if(node_dist + i.second < dist[i.first])
            {
                auto record = st.find(make_pair(dist[i.first],i.first));

                // if record found , then erace it

                if(record != st.end())
                {
                    st.erase(record);
                }

                // distance update
                
                dist[i.first] = node_dist + i.second;

                //record put in set

                st.insert(make_pair(dist[i.first],i.first));
            }
        }
    }

    return dist;
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

    vector<int> ans = s_path_dijkstra(edges,n,m,0);

    for(auto i : ans)
    {
        cout<< i<< " ";
    }
}