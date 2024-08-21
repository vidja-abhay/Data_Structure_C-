#include <bits/stdc++.h>
using namespace std;

long long int solveRec(int n) {
    if (n == 1) return 0;
    if (n == 2) return 1;
    
    return (n - 1) * (solveRec(n - 1) + solveRec(n - 2));
}

long long int solveMem(int n, vector<int> &DP){
    if (n == 1) return 0;
    if (n == 2) return 1;
    if (DP[n] != -1) return DP[n];
    
    DP[n] = (n - 1) * (solveMem(n - 1, DP) + solveMem(n - 2, DP));
    
    return DP[n];
}

long long solveTab(int n){
    vector<int> DP(n+1, -1);
    DP[1] = 0;
    DP[2] = 1;
    
    for(int i=3; i<=n; i++){
        long long int first = DP[i-1];
        long long second = DP[i-2];
        long long sum = first + second;
        long long ans = sum * (i-1);
        DP[i] = ans;
    }
    
    return DP[n];
}

long long int countDearrangement(int n) {
    // return solveRec(n);
    
    // vector<int> DP(n+1, -1);
    // return solveMem(n, DP);
    
    return solveTab(n);
}

int main() {
    int n;
    cout << "Enter a length of array which contains 1 to N numbers: ";
    cin >> n;
    
    cout << countDearrangement(n) << endl;
    return 0;
}

// A[I] != I, AA RITE GOTHAVANU 6.