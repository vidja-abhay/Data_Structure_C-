#include<bits/stdc++.h>
using namespace std;

int solve1(vector<int> &cost,int n,vector<int> &dp)
{
    if(n==0)
    {
        return cost[0];
    }

    if(n==1)
    {
        return cost[1];
    }

    if(dp[n] != -1)
    {
        return dp[n];
    }

    dp[n] = cost[n] + min(solve1(cost,n-1,dp),solve1(cost,n-2,dp));
    return dp[n];
}

int solve2(vector<int> &cost,int n)
{
    vector<int> dp(n+1);

    dp[0] = cost[0];
    dp[1] = cost[1];

    for(int i=2;i<n;i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }

    return min(dp[n-1],dp[n-2]);
}

int solve3(vector<int> &cost,int n)
{
    int prev1 = cost[1];
    int prev2 = cost[0];

    for(int i=2;i<n;i++)
    {
        int cur = cost[i] + min(prev1,prev2);

        prev2 = prev1;
        prev1 = cur;
    }

    return min(prev1,prev2);
}

int mincost(vector<int> &cost,int n)
{
    /*TOP-DOWN METHODE = RECURSION + MEMOIZATION
    vector<int> dp(n+1,-1);
    int ans = solve1(cost,n,dp);
    return ans;*/


    /*BOTTOM-UP METHODE = TABULATION
    int ans = solve2(cost,n);
    return ans;*/

    int ans = solve3(cost,n);
    return ans;
}

int main()
{
    int n; cin>>n;

    vector<int> cost(n);

    for(int i=0;i<n;i++)
    {
        cin>>cost[i];
    }

    cout<<mincost(cost,n);
}