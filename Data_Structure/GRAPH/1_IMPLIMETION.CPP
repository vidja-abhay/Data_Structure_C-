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


// #include<bits/stdc++.h>

// using namespace std;

// unordered_map<int,set<int>> createAdjcentList(vector<pair<int,int>> edges){
//     unordered_map<int,set<int>> adjList;
//     for(int i=0; i<edges.size(); i++){
//         int first = edges[i].first;
//         int second = edges[i].second;
        
//         adjList[first].insert(second);
//         adjList[second].insert(first);
//     }
    
//     return adjList;
// }

// void print(vector<pair<int,int>> edges){
//     unordered_map<int,set<int>> adjList = createAdjcentList(edges);
    
//     for(auto i : adjList){
//         cout<<i.first<<"->";
        
//         for(auto j : i.second){
//             cout<<j<<", ";
//         }
        
//         cout<<endl;
//     }
// }

// int main(){
//     int n; cin>>n;
//     int m; cin>>m;
    
//     vector<pair<int,int>> edges;
    
//     for(int i=0; i<m; i++){
//         int u,v;
//         cin>>u>>v;
        
//         pair<int,int> p = make_pair(u,v);
        
//         edges.push_back(p);
//     }
    
//     print(edges);
//     return 0;
// }