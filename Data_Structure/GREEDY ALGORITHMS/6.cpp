// MINIMUM COST OF ROPES
// GREEK FOR GREEKS

#include<bits/stdc++.h>
using namespace std;

long long solve(long long n,vector<long long> &a)
{
    priority_queue<long long,vector<long long>,greater<long long>> pq;

    for(int i=0;i<n;i++)
    {
        pq.push(a[i]);
    }

    long long cost = 0;

    while(pq.size() > 1)
    {
        long long first = pq.top();
        pq.pop();

        long long second = pq.top();
        pq.pop();

        long long mergelength = first + second;

        cost += mergelength;

        pq.push(mergelength);
    }

    return cost;
}

int main()
{
    long long n; cin>>n;

    vector<long long> a(n);

    for(long long i=0;i<n;i++)
    {
        cin>>a[i];
    }

    cout<<solve(n,a);
}