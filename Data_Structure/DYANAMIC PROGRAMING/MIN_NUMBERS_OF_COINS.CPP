#include<bits/stdc++.h>
using namespace std;

int solverec(vector<int> &num,int x)
{
    // base case

    if(x==0)
    {
        return 0;
    }

    if(x<0)
    {
        return INT_MAX;
    }

    int mini = INT_MAX;
    for(int i=0;i<num.size();i++)
    {
        int ans = solverec(num,x-num[i]);

        if(ans != INT_MAX)
        {
            mini = min(mini,1+ans);
        }
    }

    return mini;
}

int solvemem(vector<int> &num,int x,vector<int> &dp)
{
    // base case
    if(x==0)
    {
        return 0;
    }

    if(x < 0)
    {
        return INT_MAX;
    }

    if(dp[x] != -1)
    {
        return dp[x];
    }

    int mini = INT_MAX;
    for(int i=0;i<num.size();i++)
    {
        int ans = solvemem(num,x-num[i],dp);

        if(ans != INT_MAX)
        {
            mini = min(1+ans,mini);
        }
    }

    dp[x] = mini;

    return mini;
}

int solvetab(vector<int> &num,int x)
{
    vector<int> dp(x+1,INT_MAX);
    dp[0] = 0;

    for(int i=1;i<=x;i++)
    {
        for(int j=0;j<num.size();j++)
        {
            if(i-num[j] >=0 && dp[i-num[j]] != INT_MAX)
            {
                dp[i] = min(dp[i],1+dp[i-num[j]]);
            }
        }
    }

    if(dp[x] == INT_MAX)
    {
        return -1;
    }

    return dp[x];
}

int minimum(vector<int> &num,int x)
{
    /*int ans = solverec(num,x);

    if(ans == INT_MAX)
    {
        return -1;
    }

    return ans;*/

    /*vector<int> dp(x+1,-1);
    int ans = solvemem(num,x,dp);

    if(ans == INT_MAX)
    {
        return -1;
    }

    return ans;*/

    int ans = solvetab(num,x);
    return ans;
}

int main()
{
    int n;
    cin>>n;

    vector<int> num(n);

    for(int i=0;i<n;i++)
    {
        cin>>num[i];
    }

    int ammount; cin>>ammount;

    cout<<minimum(num,ammount);
}