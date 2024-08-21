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

int solveMem(vector<int> &nums, int n, vector<int> &dp){
    if(n < 0) return 0;
    if(n == 0) return nums[0];
    if(dp[n] != -1) return dp[n];
    
    int include = solveMem(nums, n-2, dp) + nums[n];
    int exclude = solveMem(nums, n-1, dp) + 0;
    
    return dp[n] = max(include, exclude);
}

long long int house(vector<int> &val)
{
    int n = val.size();

    if(n == 1)
    {
        return val[0];
    }

    vector<int> first,second;
    vector<int> dp1(n, -1);
    vector<int> dp2(n, -1);

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
    
    int n1 = first.size();
    int n2 = second.size();

    return max(solveMem(first, n1, dp1),solveMem(second, n2, dp2));
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

// Mr. X is a professional robber planning to be rob house along a street.
// Each house has a certain amount of money hidden. All houses this street are 
// arranged in circle. That means the first house is neighbour of the last one. Meanwhile
// adjacent houses have a security system connected, and i will automatically contact 
// the police if two adjacent houses were broken into on the same night.

// You are given an array of non negative integers representing the amount of money of each house. 
// your task is to return the maximum amount of money Mr. X can rob tonight without alerting police.