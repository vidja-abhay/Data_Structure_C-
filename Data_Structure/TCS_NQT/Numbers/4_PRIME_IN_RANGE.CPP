#include<bits/stdc++.h>
using namespace std;

vector<int> primeInRange(int start, int end){
    vector<bool> isPrime (end + 1, true);
    vector<int> ans;

    isPrime[0] = isPrime[1] = false;

    for(int i=2; i*i <= end ; i++){
        if(isPrime[i]){
            for(int j = i*i; j <= end; j+=i){
                isPrime[j] = false;
            }
        }
    }

    for(int i=start; i<=end; i++){
        if(isPrime[i]) ans.push_back(i);
    }

    return ans;
}

int main(){
    int startRange, endRange;
    cout<<"Enter starting number of Range & ening number of range : ";
    cin>>startRange>>endRange;

    vector<int> ans = primeInRange(startRange, endRange);

    for(auto i : ans){
        cout<<i<<" ";
    }

    return 0;
}