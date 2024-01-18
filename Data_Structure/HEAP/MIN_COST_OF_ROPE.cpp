#include<bits/stdc++.h>
using namespace std;
long long MinCost(long long a[],long long n)
{
    priority_queue<int,vector<int>,greater<int>> p;

    for(int i=0;i<n;i++)
    {
        p.push(a[i]);
    }

    long long cost = 0;

    while(p.size() > 1)
    {
        long long a = p.top();
        p.pop();

        long long b = p.top();
        p.pop();

        long long sum = a+b;

        cost += sum;

        p.push(sum);
    }

    return cost;
}

int main()
{
    long long n;
    cin>>n;
    long long a[n];

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    cout<<MinCost(a,n);
}