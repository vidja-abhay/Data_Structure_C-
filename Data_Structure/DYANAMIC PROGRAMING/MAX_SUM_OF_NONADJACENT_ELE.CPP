#include<bits/stdc++.h>
using namespace std;

int solverec(vector<int> &num,int n)
{
    // base case

    if(n<0)
    {
        return 0;
    }

    if(n == 0)
    {
        return num[0];
    }

    int incl = solverec(num,n-2) + num[n];
    int excl = solverec(num,n-1) + 0;

    return max(incl,excl);
}

int solvemem(vector<int> &num,int n,vector<int> &dp)
{
    // base case

    if(n<0)
    {
        return 0;
    }

    if(n == 0)
    {
        return num[0];
    }

    if(dp[n] != -1)
    {
        return dp[n];
    }

    int incl = solverec(num,n-2) + num[n];
    int excl = solverec(num,n-1) + 0;

    dp[n] = max(incl,excl);
    return dp[n];
}

int solvetab(vector<int> &num)
{
    int n = num.size();
    vector<int> dp(n,0);
    dp[0] = num[0];

    for(int i=1;i<n;i++)
    {
        int incl = dp[i-2] + num[i];
        int excl = dp[i-1] + 0;

        dp[i] = max(incl,excl);
    }

    return dp[n-1];
}

int spaceopt(vector<int> &num)
{
    int n = num.size();
    
    int prev2 = 0;
    int prev1 = num[0];

    for(int i=1;i<n;i++)
    {
        int incl = prev2 + num[i];
        int excl = prev1 + 0;

        int ans = max(incl,excl);

        prev2 = prev1;
        prev1 = ans;
    }

    return prev1;
}

int maxnonadjacent(vector<int> &nums)
{
    /*int n = nums.size();
    int ans = solverec(nums,n-1);
    return ans;*/

    /*int n = nums.size();
    vector<int> dp(n,-1);
    return solvemem(nums,n-1,dp);*/

   
    //return solvetab(nums);

    return spaceopt(nums);
}

int main()
{
    int n; cin>>n;
    vector<int> ans(n);

    for(int i=0;i<n;i++)
    {
        cin>>ans[i];
    }

    cout<<maxnonadjacent(ans);
}