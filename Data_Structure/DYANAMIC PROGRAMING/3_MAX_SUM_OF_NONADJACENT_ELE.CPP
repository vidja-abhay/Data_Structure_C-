#include<bits/stdc++.h>
using namespace std;

int solveRec(vector<int> &nums, int n){
    if(n < 0) return 0;
    if(n == 0) return nums[0];
    
    int include = solveRec(nums, n-2) + nums[n];
    int exclude = solveRec(nums, n-1) + 0;
    
    return max(include, exclude);
}

int solveMem(vector<int> &nums, int n, vector<int> &dp){
    if(n < 0) return 0;
    if(n == 0) return nums[0];
    if(dp[n] != -1) return dp[n];
    
    int include = solveMem(nums, n-2, dp) + nums[n];
    int exclude = solveMem(nums, n-1, dp) + 0;
    
    return dp[n] = max(include, exclude);
}

int maxSum(vector<int> &nums){
    // int n = nums.size();
    // int ans = solveRec(nums, n-1);
    // return ans;
    
    int n = nums.size();
    vector<int> dp(n, -1);
    int ans = solveMem(nums, n-1, dp);
    return ans;
}

int main(){
    int n;
    cout<<"Enter a length of vector : ";
    cin>>n;
    
    vector<int> vec(n);
    cout<<"Enter an element of vector : ";
    for(int i=0; i<n; i++){
        cin>>vec[i];
    }
    
    cout<<maxSum(vec);
}