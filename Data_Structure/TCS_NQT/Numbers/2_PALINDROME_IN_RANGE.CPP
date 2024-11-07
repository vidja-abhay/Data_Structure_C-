#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(int n){
    string s = to_string(n);

    return s == string(s.rbegin(), s.rend());
}

vector<int> palindromeInRange(int start, int end){
    vector<int> ans;

    for(int i=start; i<=end; i++){
        if(isPalindrome(i)){
            ans.push_back(i);
        }
    }

    return ans;
}

int main(){
    int startRange, endRange;
    cout<<"Enter starting number of Range & ening number of range : ";
    cin>>startRange>>endRange;

    vector<int> ans = palindromeInRange(startRange, endRange);

    for(auto i : ans){
        cout<<i<<" ";
    }

    return 0;
}