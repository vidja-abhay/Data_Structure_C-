#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(int n){
    string s = to_string(n);

    return s == string(s.rbegin(), s.rend());
}

int main(){
    int n;
    cout<<"Enter a number to check palindrome or not : ";
    cin>>n;

    if(isPalindrome(n)) cout<<"Given number is palindrome"<<endl;
    else cout<<"Given number is not plaindrome"<<endl;

    return 0;
}