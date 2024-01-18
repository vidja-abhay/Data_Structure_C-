#include<bits/stdc++.h>
using namespace std;

long long int spaceopt(vector<int> &num)
{
    long long int n = num.size();
    
    long long int prev2 = 0;
    long long int prev1 = num[0];

    for(int i=1;i<n;i++)
    {
        long long int incl = prev2 + num[i];
        long long int excl = prev1 + 0;

        long long int ans = max(incl,excl);

        prev2 = prev1;
        prev1 = ans;
    }

    return prev1;
}

long long int house(vector<int> &val)
{
    int n = val.size();

    if(n == 1)
    {
        return val[0];
    }

    vector<int> first,second;

    for(int i=0;i<n;i++)
    {
        if( i != n-1)
        {
            first.push_back(val[i]);
        }

        if(i != 0)
        {
            second.push_back(val[i]);
        }
    }

    return max(spaceopt(first),spaceopt(second));
}

int main()
{
    int n; cin>>n;
    vector<int> ans(n);

    for(int i=0;i<n;i++)
    {
        cin>>ans[i];
    }

    cout<<house(ans);
}