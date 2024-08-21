#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    getline(cin, s);

    string rev = "";

    for(int i=s.length()-1;i>=0;i--){
        rev.push_back(s[i]);
    }

    cout<<"Reverse string without use library : "<<rev<<endl;

    string rev2 = string(s.rbegin(), s.rend());

    cout<<"Reverse string using library : "<<rev2<<endl;

    return 0;
}

// Write a program to reverse a string without using any library function.