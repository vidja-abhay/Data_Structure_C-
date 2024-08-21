#include<bits/stdc++.h>
using namespace std;

int solveRec(vector<int> &v, int i, int j){
    if(i+1 == j) return 0;

    int ans = INT_MAX;

    for(int k=i+1; k<j; k++){
        ans = min(ans , v[i]*v[j]*v[k] + solveRec(v, i, k) + solveRec(v, k, j));
    }

    return ans;
}

int solveMem(vector<int> &v, int i, int j, vector<vector<int>> &dp){
    if(i+1 == j) return 0;
    
    if(dp[i][j] != -1) return dp[i][j];

    int ans = INT_MAX;

    for(int k=i+1; k<j; k++){
        ans = min(ans , v[i]*v[j]*v[k] + solveRec(v, i, k) + solveRec(v, k, j));
    }
    
    dp[i][j] = ans;

    return dp[i][j];
}

int solveTab(vector<int> &v){
    int n = v.size();
    vector<vector<int>> dp(n, vector<int>(n,0));
    
    for(int i=n-1; i>=0; i--){
        for(int j=i+2; j<n; j++){
            int ans = INT_MAX;
            for(int k=i+1; k<j; k++){
                ans = min(ans, v[i]*v[k]*v[j] + dp[i][k] + dp[k][j]);
            }
            dp[i][j] = ans;
        }
    }
    
    return dp[0][n-1];
}

int maxScore(vector<int> &value){
    // int n = value.size();
    // return solveRec(value, 0, n-1);
    
    // int n = value.size();
    // vector<vector<int>> dp(n, vector<int>(n,-1));
    // return solveMem(value, 0, n-1, dp);
    
    return solveTab(value);
}

int main(){
    int n;
    cout<<"Enter a number of vertex for polygon : ";
    cin>>n;

    vector<int> value(n);
    cout<<"Enter a values of each vertex : ";
    for(int i=0; i<n; i++){
        cin>>value[i];
    }

    cout << maxScore(value);
}