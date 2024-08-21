#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(int n){
    string s = to_string(n);
    
    return s == string(s.rbegin(), s.rend());
}

vector<int> palinromeInGivenRange(int start, int end){
    vector<int> palindrome;
    
    for(int i=start; i<=end; i++){
        if(isPalindrome(i)){
            palindrome.push_back(i);
        }
    }
    
    return palindrome;
}

void print(vector<int> vec){
    for(auto items : vec){
        cout<<items<<" ";
    }
}

int main(){
    int start,end;
    cin>>start;
    cin>>end;
    
    vector<int> palindrome = palinromeInGivenRange(start,end);
    
    print(palindrome);
    return 0;
}