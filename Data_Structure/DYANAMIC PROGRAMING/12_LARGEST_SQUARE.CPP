#include<bits/stdc++.h>
using namespace std;

int solveRec(vector<vector<int>> &mat, int i, int j, int &maxi){
    if(i >= mat.size() || j >= mat[0].size()) return 0;

    int right = solveRec(mat, i, j+1, maxi);
    int diagonal = solveRec(mat, i+1, j+1, maxi);
    int down = solveRec(mat, i+1, j, maxi);

    if(mat[i][j] == 1){
        int ans = 1 + min(right, min(diagonal, down));
        maxi = max(maxi, ans);
        return ans;
    }

    else{
        return 0;
    }
}

int solveMem(vector<vector<int>> &mat, int i, int j, int &maxi, vector<vector<int>> &dp){
    if(i >= mat.size() || j >= mat[0].size()) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    int right = solveMem(mat, i, j+1, maxi, dp);
    int diagonal = solveMem(mat, i+1, j+1, maxi, dp);
    int down = solveMem(mat, i+1, j, maxi, dp);

    if(mat[i][j] == 1){
        dp[i][j] = 1 + min(right, min(diagonal, down));
        maxi = max(maxi, dp[i][j]);
        return dp[i][j];
    }

    else{
        return dp[i][j] = 0;
    }
}

int solveTab(vector<vector<int>> &mat, int &maxi){
    int m = mat.size();
    int n = mat[0].size();

    vector<vector<int>> dp(m+1, vector<int>(n+1,0));

    for(int i=m-1; i>=0; i--){
        for(int j=n-1; j>=0; j--){
            int right = dp[i][j+1];
            int diagonal = dp[i+1][j+1];
            int down = dp[i+1][j];

            if(mat[i][j] == 1){
                dp[i][j] = 1 + min(right, min(diagonal, down));
                maxi = max(maxi, dp[i][j]);
            }

            else{
                dp[i][j] = 0;
            }
        }
    }
    
    return dp[0][0];
}


int maxSquare(vector<vector<int>> &mat, int m, int n){
    // int maxi = 0;
    // solveRec(mat, 0, 0, maxi);
    // return maxi;

    // int maxi = 0;
    // vector<vector<int>> dp(m, vector<int>(n,-1));
    // solveMem(mat, 0, 0, maxi,dp);
    // return maxi;

    int maxi = 0;
    solveTab(mat,maxi);
    return maxi;
}

int main(){
    int n,m;
    cout<<"Enter a number of rows and columns of matrix : ";
    cin>>m>>n;

    vector<vector<int>> mat(m, vector<int>(n));

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>mat[i][j];
        }
    }

    cout<<maxSquare(mat,m,n);
}