// CHOCOLATE DISTRIBUTION PROBELEM
// GREEK FOR GREEKS

#include<bits/stdc++.h>
using namespace std;

long long FindMinDif(long long n,vector<long long> &a,long long m)
{
    sort(a.begin(),a.end());

    int i = 0;
    int j = m-1;
    int mini = INT_MAX;

    while(j < n)
    {
        int dif = a[j] - a[i];
        mini = min(mini,dif);

        j++;
        i++;
    }

    return mini;
}

int main()
{
    long long n;
    cin>>n;
    vector<long long> a(n);

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    long long m; cin>>m;

    long long ans = FindMinDif(n,a,m);
    cout<<ans;

    return 0;
}