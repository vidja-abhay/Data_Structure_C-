#include<bits/stdc++.h>
using namespace std;

int catlan(int n)
{
    if(n<=1)
    {
        return 1;
    }
    int ans = 0;
    for(int i=0;i<=n-1;i++)
    {
        ans += catlan(i)*catlan(n-1-i);
    }
    return ans;
}

int main()
{
    int n; cin>>n;
    // for(int i=0;i<=n;i++)
    // {
    //     cout<<catlan(i)<<" ";
    // }
    cout<<catlan(n);

    return 0;
}