#include<bits/stdc++.h>
using namespace std;

int solveRec(int n, int k){
    if(n == 1) return k;
    if(n == 2) return k + k*(k-1);
    
    int ans = solveRec(n-1, k)*(k-1) + solveRec(n-2, k)*(k-1);
    
    return ans;
}

int solveMem(int n, int k, vector<int>& DP){
    if(n == 1) return k;
    if(n == 2) return k + k*(k-1);
    if(DP[n] != -1) return DP[n];
    
    DP[n] = solveRec(n-1, k)*(k-1) + solveRec(n-2, k)*(k-1);
    
    return DP[n];
}

int solveTab(int n, int k){
    vector<int> DP(n+1);
    DP[1] = k;
    DP[2] = k + k*(k-1);
    
    for(int i=3; i<=n; i++){
        DP[i] = DP[i-1]*(k-1) + DP[i-2]*(k-1);
    }
    
    return DP[n];
}

int numberOfWays(int n, int k){
    // return solveRec(n, k);
    
    // vector<int> DP(n+1, -1);
    // return solveMem(n, k, DP);
    
    return solveTab(n, k);
}

int main(){
    int n;
    cout<<"Enter a number of posts : ";
    cin>>n;
    
    int k;
    cout<<"Enter a number of color : ";
    cin>>k;
    
    cout<<numberOfWays(n, k);
}

// Ninja has a given fence, and he gave a task to paint this fence. The fence has 'N' posts and Ninja has 'K' color.
// Ninja wants to paint the fence so that not more than two adjacent post have the same color.

// Ninja wonders how many ways are there to do the above task. so he asked for your help.