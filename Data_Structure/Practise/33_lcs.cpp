#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string longestCommonSubsequence(string text1, string text2) {
    int m = text1.length();
    int n = text2.length();
    
    // Create a 2D table for storing LCS lengths
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    
    // Fill the dp table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (text1[i - 1] == text2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    
    // Reconstruct the LCS
    string lcs = "";
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (text1[i - 1] == text2[j - 1]) {
            lcs = text1[i - 1] + lcs;
            i--; j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    
    return lcs;
}

int main() {
    string str1, str2;
    
    cout << "Enter first string: ";
    cin >> str1;
    
    cout << "Enter second string: ";
    cin >> str2;
    
    string lcs = longestCommonSubsequence(str1, str2);
    
    cout << "Longest Common Subsequence: " << lcs << endl;
    cout << "Length of LCS: " << lcs.length() << endl;
    
    return 0;
}