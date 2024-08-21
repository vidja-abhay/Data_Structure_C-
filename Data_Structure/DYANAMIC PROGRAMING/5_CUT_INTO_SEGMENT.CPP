#include<bits/stdc++.h>
using namespace std;

int solveRec(int n, int x, int y, int z){
    if(n == 0){
        return 0;
    }

    if(n < 0){
        return INT_MIN;
    }

    int a = solveRec(n-x, x, y, z) + 1;
    int b = solveRec(n-y, x, y, z) + 1;
    int c = solveRec(n-y, x, y, z) + 1;

    int ans = max(a, max(b, c));

    return ans;
}

int solveMem(int n, int x, int y, int z, vector<int> &DP){
    if(n == 0){
        return 0;
    }
    
    if(n < 0){
        return INT_MIN;
    }
    
    if(DP[n] != -1){
        return DP[n];
    }
    
    int a = solveMem(n-x, x, y, z, DP) + 1;
    int b = solveMem(n-y, x, y, z, DP) + 1;
    int c = solveMem(n-y, x, y, z, DP) + 1;
    
    int ans = max(a, max(b, c));
    
    DP[n] = ans;
    
    return DP[n];
}

int solveTab(int n, int x, int y, int z){
    vector<int> DP(n+1, -1);
    DP[0] = 0;
    
    for(int i=1; i<=n; i++){
        if(i-x >= 0 && DP[i-x] != -1){
            DP[i] = max(DP[i], DP[i-x] + 1);
        }
        
        if(i-y >= 0 && DP[i-y] != -1){
            DP[i] = max(DP[i], DP[i-y] + 1);
        }
        
        if(i-z >= 0 && DP[i-z] != -1){
            DP[i] = max(DP[i], DP[i-z] + 1);
        }
    }
    
    if(DP[n] < 0){
        return 0;
    }
    else{
        return DP[n];
    }
}

int cutIntoSegment(int n, int x, int y, int z){
    // int ans = solveRec(n, x, y, z);
    // if(ans < 0)
    //     return 0;
    // else 
    //     return ans;
    
    // vector<int> DP(n+1, -1);
    // int ans = solveMem(n, x, y, z, DP);
    // if(ans < 0)
    //     return 0;
    // else
    //     return ans;
    
    return solveTab(n, x, y, z);
}

int main(){
    int n;
    cout<<"Enter a length of Rod : ";
    cin>>n;

    int x,y,z;
    cout<<"Enter a length of three segment : ";
    cin>>x>>y>>z;

    cout<<cutIntoSegment(n, x, y, z);
}