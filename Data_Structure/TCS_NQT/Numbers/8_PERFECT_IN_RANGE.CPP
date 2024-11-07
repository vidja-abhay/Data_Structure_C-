#include<bits/stdc++.h>
using namespace std;

bool isPerfect(int n){
    int sum = 0;

    for(int i=1; i<=n; i++){
        if(n%i == 0) sum += i;
    }

    return sum == 2*n;
}

vector<int> perfectInRange(int start, int end){
    vector<int> ans;

    for(int i=start; i<=end; i++){
        if(isPerfect(i)) ans.push_back(i);
    }

    return ans;
}

int main(){
    int startRange, endRange;
    cout<<"Enter starting number of Range & ening number of range : ";
    cin>>startRange>>endRange;

    vector<int> ans = perfectInRange(startRange, endRange);

    for(auto i : ans){
        cout<<i<<" ";
    }

    return 0;
}