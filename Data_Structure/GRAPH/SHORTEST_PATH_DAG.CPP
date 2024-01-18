#include<bits/stdc++.h>
using namespace std;

class Graph
{
    public :

    unordered_map<int,list<pair<int,int>>> adj;

    void AddEdges(int u,int v,int weight)
    {
        pair<int,int> p = make_pair(v,weight);

        adj[u].push_back(p);
    }

    void PrintEdges()
    {
        for(auto i : adj)
        {
            cout<<i.first<<"->";

            for(auto j : i.second)
            {
                cout<<"("<<j.first<<","<<j.second<<"), ";
            }
            cout<<endl;
        }
    }

    void dfs(int node,unordered_map<int,bool> &visited,stack<int> &s)
    {
        visited[node] = true;

        for(auto i : adj[node])
        {
            if(!visited[i.first])
            {
                dfs(i.first,visited,s);
            }
        }

        s.push(node);
    }

    void GetShortestPath(int src,vector<int> &dist,stack<int> &s)
    {
        dist[src] = 0;

        while(!s.empty())
        {
            int top = s.top();
            s.pop();

            if(dist[top] != INT_MAX)
            {
                for(auto i : adj[top])
                {
                    if(dist[top] + i.second < dist[i.first])
                    {
                        dist[i.first] = dist[top] + i.second;
                    }
                }
            }
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

    Graph g;

    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;

        g.AddEdges(u,v,w);
    }

    g.PrintEdges();
    cout<<endl;

    // topological sort

    unordered_map<int,bool> visited;
    stack<int> s;
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            g.dfs(i,visited,s);   // adj graph ma hovathi
        }
    }

    int src;
    cout<<"ENTER THE SRC NODE : ";
    cin>>src;

    vector<int> dist(n);

    for(int i=0;i<n;i++)
    {
        dist[i] = INT_MAX;
    }

    g.GetShortestPath(src,dist,s);

    for(auto i : dist)
    {
        cout<<i<<" ";
    }    

}


/*without creat class of graph

#include<bits/stdc++.h>
using namespace std;

void GetShortestPath(int src,vector<int> &dist,stack<int> &s,unordered_map<int,list<pair<int,int>>> adj)
{
		dist[src] = 0;

        while(!s.empty())
        {
            int top = s.top();
            s.pop();

            if(dist[top] != INT_MAX)
            {
                for(auto i : adj[top])
                {
                    if(dist[top] + i.second < dist[i.first])
                    {
                        dist[i.first] = dist[top] + i.second;
                    }
                }
            }
        }
}

void toposort(int node,unordered_map<int,bool> &visited,stack<int> &s,unordered_map<int,list<pair<int,int>>> adj)
{
    visited[node] = 1;

    for(auto i : adj[node])
    {
        if(!visited[i.first])
        {
            toposort(i.first,visited,s,adj);
        }
    }

    s.push(node);
}

void solve(vector<pair<int,pair<int,int>>> &edges,int n,int m,int src,vector<int> &dist)
{
	unordered_map<int,list<pair<int,int>>> adj;

	for(int i=0;i<m;i++)
	{
		int u = edges[i].first;
		pair<int,int> v = edges[i].second;

		adj[u].push_back(v);
	}

	unordered_map<int,bool> visited;
    stack<int> s;

	for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            toposort(i,visited,s,adj);
        }
    }

	GetShortestPath(src,dist,s,adj);
}

int main()
{
	int n;
    cout<<"ENTER THE NUMBER OF NODES : ";
    cin>>n;

    int m;
    cout<<"ENTER THE NUMBER OF EDGES : ";
    cin>>m;

	vector<pair<int,pair<int,int>>> edges;

	for(int i=0;i<m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;

		pair<int,int> p = make_pair(v,w);

		pair<int,pair<int,int>> ans = make_pair(u,p);

		edges.push_back(ans);
	}

	int src;
    cout<<"ENTER THE SRC NODE : ";
    cin>>src;

    vector<int> dist(n);

    for(int i=0;i<n;i++)
    {
        dist[i] = INT_MAX;
    }

	solve(edges,n,m,src,dist);

	for(auto i : dist)
	{
		cout<<i<<" ";
	}
}*/