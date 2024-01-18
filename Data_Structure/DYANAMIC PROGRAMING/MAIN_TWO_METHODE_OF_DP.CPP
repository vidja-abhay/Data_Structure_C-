// TOP-DOWN METHODE = RECURSION + MEMOIZATION
// BOTTOM-UP METHODE = TABULATION


/* TOP-DOWN METHODE = RECURSION + MEMOIZATION
#include<bits/stdc++.h>
using namespace std;

int fib(int n,vector<int> &dp)
{
    // base case

    if(n <= 1)
    {
        return n;
    }

    if(dp[n] != -1)
    {
        return dp[n];
    }


    // step 2

    dp[n] = fib(n-1,dp) + fib(n-2,dp);
    return dp[n];
}

int main()
{
    int n; cin>>n;

    // create a vector of dp
    vector<int> dp(n+1);

    for(int i=0;i<=n;i++)
    {
        dp[i] = -1;
    }

    cout<< fib(n,dp) <<endl;

    return 0;
}*/


/* BOTTOM-UP METHODE = TABULATION

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin>>n;

    vector<int> dp(n+1);

    dp[0] = 0;
    dp[1] = 1;

    for(int i=2;i<=n;i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }

    // only n-th position mate cout<<dp[n]

    for(auto i : dp)
    {
        cout<<i<<" ";
    }
}*/