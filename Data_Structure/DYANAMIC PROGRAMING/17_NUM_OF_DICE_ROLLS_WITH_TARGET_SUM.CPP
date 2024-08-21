#include<bits/stdc++.h>
using namespace std;

long long solveRec(int faces, int dice, int target){
    if(target < 0) return 0;
    if(dice == 0 && target != 0) return 0;
    if(dice != 0 && target == 0) return 0;
    if(dice == 0 && target == 0) return 1;

    long long ans = 0;
    for(int i=1; i<=faces; i++){
        ans += solveRec(faces, dice-1, target-i);
    }

    return ans;
}

long long solveMem(int faces, int dice, int target, vector<vector<long long>> &dp){
    if(target < 0) return 0;
    if(dice == 0 && target != 0) return 0;
    if(dice != 0 && target == 0) return 0;
    if(dice == 0 && target == 0) return 1;
    if(dp[dice][target] != -1) return dp[dice][target];

    long long ans = 0;
    for(int i=1; i<=faces; i++){
        ans += solveRec(faces, dice-1, target-i);
    }

    return dp[dice][target] = ans;
}

long long numberOfWays(int faces, int dice, int target){
    // return solveRec(faces, dice, target);
    
    vector<vector<long long>> dp(dice+1, vector<long long>(target+1, -1));
    return solveMem(faces, dice, target, dp);
}

int main(){
    int n;
    cout<<"Enter a number of dice : ";
    cin>>n;

    int m;
    cout<<"Enter a number of faces of dice : ";
    cin>>m;

    int x;
    cout<<"Enter target : ";
    cin>>x;

    cout<<numberOfWays(m, n, x);
}