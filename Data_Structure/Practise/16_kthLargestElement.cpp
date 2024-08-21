#include<bits/stdc++.h>
using namespace std;

int solve(int a[],int n,int k)
{
    priority_queue<int,vector<int>,greater<int>> p;

    for(int i=0;i<k;i++)
    {
        p.push(a[i]);
    }

    for(int i=k;i<n;i++)
    {
        if(p.top() < a[i])
        {
            p.pop();

            p.push(a[i]);
        }
    }

    int ans = p.top();

    return ans;
}

int main()
{
    int n; cin>>n;
    int a[n];

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    cout<<solve(a,n,4);
}