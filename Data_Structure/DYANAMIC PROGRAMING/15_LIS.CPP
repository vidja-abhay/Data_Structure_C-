#include<bits/stdc++.h>
using namespace std;

int solveRec(vector<int> &vec,int size, int cur, int prev){
    if(cur == size){
        return 0;
    }

    int include = 0;
    if(prev == -1 || vec[cur] > vec[prev]){
        include = 1 + solveRec(vec, size, cur+1, cur);
    }
    int exclude = 0 + solveRec(vec, size, cur+1, prev);

    return max(include, exclude);
}

int maxLIS(vector<int> &vec){
    int n = vec.size();
    return solveRec(vec, n, 0, -1);
}

int main(){
    int n;
    cout<<"Enter a length of an array : ";
    cin>>n;

    vector<int> vec(n);
    cout<<"Enter a an element of an array : ";
    for(int i=0; i<n; i++){
        cin>>vec[i];
    }

    cout<<maxLIS(vec);
}


// static bool customCompare(const vector<int>& a, const vector<int>& b) {
//     if (a[0] != b[0]) {
//         return a[0] < b[0];
//     } else {
//         return a[1] > b[1];
//     }
// }

// // Helper function for LIS
// int LISHelper(vector<vector<int>>& v, int prev, int current, vector<vector<int>>& memo) {
//     if (current == v.size()) return 0;
    
//     if (prev != -1 && memo[prev][current] != -1) return memo[prev][current];
    
//     int take = 0;
//     if (prev == -1 || v[current][0] > v[prev][0]) {
//         take = 1 + LISHelper(v, current, current + 1, memo);
//     }
    
//     int skip = LISHelper(v, prev, current + 1, memo);
    
//     if (prev != -1) memo[prev][current] = max(take, skip);
    
//     return max(take, skip);
// }
    
//     int maxEnvelopes(vector<vector<int>>& v) {
//         sort(v.begin(), v.end(), customCompare);
//     int n = v.size();
//     vector<vector<int>> memo(n, vector<int>(n, -1));
//     return LISHelper(v, -1, 0, memo);
//     }