#include <bits/stdc++.h>
using namespace std;

int solveRec(int n){
    if(n == 0) return 0;
    int ans = n;
    for(int i=1; i*i<=n; i++){
        int temp = i*i;
        ans = min(ans, 1 + solveRec(n-temp));
    }
    return ans;
}

int solveMem(int n, vector<int>& dp) {
    if (n == 0) return 0;
    if (dp[n] != -1) return dp[n];

    int ans = n;
    for (int i = 1; i * i <= n; i++) {
        int temp = i * i;
        ans = min(ans, 1 + solveMem(n - temp, dp));
    }
    return dp[n] = ans;
}

int solveTab(int n){
    vector<int> DP(n+1, INT_MAX);
    
    DP[0] = 0;
    
    for(int i=1; i<=n; i++){
        for(int j=1; j*j <= n; j++){
            int temp = j*j;
            
            if(i-temp >= 0){
                DP[i] = min(DP[i], 1 + DP[i-temp]);
            }
        }
    }
    
    return DP[n];
}

int numberOfWays(int n) {
    // return solveRec(n);
    
    // vector<int> dp(n + 1, -1);
    // return solveMem(n, dp);
    
    return solveTab(n);
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Minimum number of perfect squares: " << numberOfWays(n) << endl;
    return 0;
}

// Given a number "N". Find the minimum number of squares of any number that sums of to N. Ex : N = 100, N can be
// expressed as (10*10) and also(5*5 + 5*5 + 5*5 + 5*5) but the output will be 1 as minimum.