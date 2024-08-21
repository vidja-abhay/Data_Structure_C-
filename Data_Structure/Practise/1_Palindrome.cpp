#include<bits/stdc++.h>
using namespace std;

bool isPalingrome(string s){
    return s == string(s.rbegin(), s.rend());
}

int main(){
    string s;
    getline(cin, s);

    if(isPalingrome(s)){
        cout<<"Given string is plindrome : "<<s<<endl;
    }
    else{
        cout<<"Given string is not palinrome : "<<s<<endl;
    }
    return 0;
}

// Implement a function to check if a given string is a palindrome.