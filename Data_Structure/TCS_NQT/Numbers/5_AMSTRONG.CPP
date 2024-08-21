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

int mani(){
    int n;
    cout<<"Enter a number to check number is amstrong or not : ";
    cin>>n;

    if(isAmstrong(n)) cout<<"This number is amstrong Number"<<endl;
    else cout<<"This number is not amstrong number"<<endl;

    return 0;
}