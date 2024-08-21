#include<bits/stdc++.h>
using namespace std;

 int countCommonSubsequences(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();
        
        // Create a 2D DP table
        vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, 0));
        
        // Initialize first row and column
        for (int i = 0; i <= m; i++) {
            dp[i][0] = 1;
        }
        for (int j = 0; j <= n; j++) {
            dp[0][j] = 1;
        }
        
        // Fill the DP table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s1[i-1] == s2[j-1]) {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                } else {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
                }
            }
        }
        
        // The result is the value at dp[m][n] minus 1 to exclude the empty subsequence
        return dp[m][n] - 1;
    }

int main(){
    string s1;
    getline(cin, s1);
    
    string s2;
    getline(cin, s2);
    
    int ans = countCommonSubsequences(s1, s2);
    cout<<ans;
    
    
}