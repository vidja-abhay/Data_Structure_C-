// N MEETING IN ONE ROOM
// GREEK FOR GREEKS

#include<bits/stdc++.h>
using namespace std;

static bool cmp(pair<int,int> a,pair<int,int> b)
{
    return a.second < b.second;
}

int MakeMeetings(vector<int> &start,vector<int> &end,int n)
{
    vector<pair<int,int>> v;

    for(int i=0;i<n;i++)
    {
        pair<int,int> p = make_pair(start[i],end[i]);
        v.push_back(p);
    }

    sort(v.begin(),v.end(),cmp);

    int count = 1;
    int ansEnd = v[0].second;

    for(int i=1;i<n;i++)
    {
        if(v[i].first > ansEnd)
        {
            count++;
            ansEnd = v[i].second;
        }
    }

    return count;
}

int main()
{
    int n; cin>>n;
    vector<int> start(n);
    vector<int> end(n);

    cout<<"ENTER START TIME : ";
    for(int i=0;i<n;i++)
    {
        cin>>start[i];
    }
    cout<<"ENTER END TIME : ";
    for(int i=0;i<n;i++)
    {
        cin>>end[i];
    }

    int ans = MakeMeetings(start,end,n);
    cout<<ans;
}