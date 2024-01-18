#include<bits/stdc++.h>
using namespace std;

class node
{
    public :

    int data;
    int a_pos;
    int v_pos;

    node(int d,int ap,int vp)
    {
        data = d;
        a_pos = ap;
        v_pos = vp;
    }
};

class compare
{
    public :

    bool operator()(node* a,node* b)
    {
        return a->data > b->data;
    }
};

vector<int> solve(vector<vector<int>> a,int k)
{
    vector<int> ans;

    priority_queue<node*,vector<node*>,compare> pq;

    for(int i=0;i<k;i++)
    {
        pq.push(new node(a[i][0],i,0));
    }

    while(!pq.empty())
    {
        node* temp = pq.top();
        pq.pop();

        ans.push_back(temp->data);

        int ap = temp->a_pos , vp = temp->v_pos;

        if(vp + 1 < k)                  // k ni jagya e a[ap].size()  chale
        {
            pq.push(new node(a[ap][vp+1],ap,vp+1));
        }
    }

    return ans;
}

int main()
{
    int n;
    cin>>n;

    vector<vector<int>> a(n,vector<int>(n));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }

    vector<int> ans = solve(a,n);

    for(auto i : ans)
    {
        cout<<i<<" ";
    }
}