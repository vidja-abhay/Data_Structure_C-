#include<bits/stdc++.h>
using namespace std;

int solveRec(int n, vector<int> days, vector<int> cost, int index){
    if(index >= n) return 0;

    int option1 = cost[0] + solveRec(n, days, cost, index+1);

    int i;
    for(int i=index; i<n && days[i] < days[index]+7; i++);
    int option2 = cost[1] + solveRec(n, days, cost, i);

    int j;
    for(int j=index; j<n && days[j] < days[index]+30; j++);
    int option3 = cost[2] + solveRec(n, days, cost, j);

    return min(option1, min(option2, option3));
}

int solveMem(int n, vector<int> &days, vector<int> &cost, int index, vector<int> &dp) {
    if (index >= n) return 0;
    
    if (dp[index] != -1) return dp[index];
    
    int option1 = cost[0] + solveMem(n, days, cost, index + 1, dp);
    
    int i = index;
    while (i < n && days[i] < days[index] + 7) i++;
    int option2 = cost[1] + solveMem(n, days, cost, i, dp);
    
    int j = index;
    while (j < n && days[j] < days[index] + 30) j++;
    int option3 = cost[2] + solveMem(n, days, cost, j, dp);
    
    return dp[index] = min(option1, min(option2, option3));
}

int solveTab(int n, vector<int> &days, vector<int> &cost) {
    vector<int> dp(n + 1, INT_MAX);
    
    dp[n] = 0;
    
    for (int k = n - 1; k >= 0; k--) {
        // Option 1: Buy a 1-day pass
        int option1 = cost[0] + dp[k + 1];
        
        // Option 2: Buy a 7-day pass
        int i = k;
        while (i < n && days[i] < days[k] + 7) i++;
        int option2 = cost[1] + (i < n ? dp[i] : 0);
    
        // Option 3: Buy a 30-day pass
        int j = k;
        while (j < n && days[j] < days[k] + 30) j++;
        int option3 = cost[2] + (j < n ? dp[j] : 0);
        
        dp[k] = min(option1, min(option2, option3));
    }
    
    return dp[0];
}

int minimumCost(int n, vector<int> days, vector<int> cost){
    // return solveRec(n, days, cost, 0); // 0 index thi start

    // vector<int> dp(n, -1);
    // return solveMem(n, days, cost, 0, dp);
    
    return solveTab(n, days, cost);
}

int main(){
    int n;
    cout<<"Enter a number of days Ninja wants to travel : ";
    cin>>n;

    vector<int> days(n);
    cout<<"Enter a day number, Ninja wants to travel : ";
    for(int i=0; i<n; i++){
        cin>>days[i];
    }

    vector<int> cost(3);
    cout<<"Enter a cost value of 1,7,30 days pass : ";
    for(int i=0; i<3; i++){
        cin>>cost[i];
    }

    cout<<minimumCost(n, days, cost);
}