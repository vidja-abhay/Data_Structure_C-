#include<bits/stdc++.h>
using namespace std;

int getLength(int n){
    string s = to_string(n);
    return s.length();
}

bool isAmstrong(int n){
    int len = getLength(n);

    int temp = n;
    int sum = 0;

    while(temp > 0){
        sum += pow(temp%10, len);
        temp /= 10;
    }

    if(n == sum) return true;
    else return false;
}

vector<int> amstrongInRange(int start, int end){
    vector<int> ans;

    for(int i=start; i<=end; i++){
        if(isAmstrong(i)){
            ans.push_back(i);
        }
    }

    return ans;
}

int main(){
    int startRange, endRange;
    cout<<"Enter starting number of Range & ening number of range : ";
    cin>>startRange>>endRange;

    vector<int> ans = amstrongInRange(startRange, endRange);

    for(auto i : ans){
        cout<<i<<" ";
    }

    return 0;
}