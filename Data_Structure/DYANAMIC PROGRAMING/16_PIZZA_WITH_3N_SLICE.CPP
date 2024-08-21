#include<bits/stdc++.h>
using namespace std;

int solveRec(int index, int endIndex, vector<int> &slice, int n){
    if(n == 0 || index > endIndex) return 0;
    
    int eat = slice[index] + solveRec(index+2, endIndex, slice, n-1);
    int notEat = 0 + solveRec(index+1, endIndex, slice, n);
    
    return max(eat, notEat);
}

int solveMem(int index, int endIndex, vector<int> &slice, int n, vector<vector<int>> &dp){
    if(n == 0 || index > endIndex) return 0;

    if(dp[index][n] != -1) return dp[index][n];
    
    int eat = slice[index] + solveMem(index+2, endIndex, slice, n-1, dp);
    int notEat = 0 + solveMem(index+1, endIndex, slice, n, dp);
    
    return dp[index][n] = max(eat, notEat);
}

int maxSliceEat(vector<int> &slice){
    // int k = slice.size();
    // int case1 = solveRec(0, k-2, slice, k/3);
    // int case2 = solveRec(1, k-1, slice, k/3);
    // return max(case1, case2);

    int k = slice.size();
    vector<vector<int>> dp1(k, vector<int>(k/3 + 1,-1));
    int case1 = solveMem(0, k-2, slice, k/3, dp1);
    vector<vector<int>> dp2(k, vector<int>(k/3 + 1,-1));
    int case2 = solveMem(1, k-1, slice, k/3, dp2);
    return max(case1, case2);
}

int main(){
    int n; 
    cout<<"Enter a number of slices of Pizza : ";
    cin>>n;

    vector<int> slice(n);
    for(int i=0; i<n; i++){
        cin>>slice[i];
    }

    cout<<maxSliceEat(slice);
}