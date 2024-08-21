#include<bits/stdc++.h>
using namespace std;

int solveRec(vector<int> &weight, vector<int> &value, int index, int capacity){
    // Base Case
    if(index == 0){
        if(weight[0] <= capacity){
            return value[0];
        }
        else{
            return 0;
        }
    }

    int include = 0;
    if(weight[index] <= capacity){
        include = value[index] + solveRec(weight, value, index-1, capacity-weight[index]);
    }

    int exclude = 0 + solveRec(weight, value, index-1, capacity);

    int ans = max(include, exclude);

    return ans;
}

int solveMem(vector<int> &weight, vector<int> &value, int index, int capacity, vector<vector<int>> &DP) {
    if (index == 0) {
        if (weight[0] <= capacity) {
            return value[0];
        } else {
            return 0;
        }
    }
    
    if (DP[index][capacity] != -1) return DP[index][capacity];
    
    int include = 0;
    if (weight[index] <= capacity) {
        include = value[index] + solveMem(weight, value, index-1, capacity-weight[index], DP);
    }
    int exclude = 0 + solveMem(weight, value, index-1, capacity, DP);
    DP[index][capacity] = max(include, exclude);
    return DP[index][capacity];
}

int solveTab(vector<int> &weight, vector<int> &value, int n, int capacity){
    vector<vector<int>> DP(n, vector<int>(capacity+1, 0));
    
    for(int w=weight[0]; w<=capacity; w++){
        
            if (weight[0] <= capacity) {
                DP[0][w] = value[0];
            } else {
                DP[0][w] = 0;
            }
        
    }
    
    for(int index=1; index<n; index++){
        for(int w=0; w<=capacity; w++){
            int include = 0;
            if (weight[index] <= w) {
                include = value[index] + DP[index-1][w - weight[index]];
            }
            int exclude = DP[index-1][w] + 0;
            DP[index][w] = max(include, exclude);
        }
    }
    
    return DP[n-1][capacity];
}

int kanpsake(vector<int> &weight, vector<int> &value, int n, int maxWeight){
    // return solveRec(weight, value, n-1, maxWeight);
    
    // vector<vector<int>> DP(n, vector<int>(maxWeight+1, -1));
    // return solveMem(weight, value, n-1, maxWeight, DP);
    
    return solveTab(weight, value, n, maxWeight);
}

int main(){
    int n;
    cout<<"Enter a number of items : ";
    cin>>n;

    vector<int> weight(n);
    vector<int> value(n);

    cout<<"Enter a weight of each item : ";
    for(int i=0; i<n; i++){
        cin>>weight[i];
    }

    cout<<"Enter a values of each item : ";
    for(int i=0; i<n; i++){
        cin>>value[i];
    }

    int maxWeight;
    cout<<"Enter a capacity of knapsake : ";
    cin>>maxWeight;

    cout<<kanpsake(weight, value, n, maxWeight);

    return 0;
}