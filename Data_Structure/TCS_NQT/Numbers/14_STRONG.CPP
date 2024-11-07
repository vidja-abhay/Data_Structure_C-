#include<bits/stdc++.h>
using namespace std;

int factorial(int n){
    if(n == 0 || n == 1) return 1;

    return factorial(n-1) * n;
}

bool isStrong(int n){
    int sum = 0;
    int temp = n;

    while(temp > 0){
        sum += factorial(temp%10);
        temp /= 10;
    }

    return sum == n;
}

int main(){
    int n;
    cout<<"Enter a number to check nuber is strong or not : ";
    cin>>n;

    if(isStrong(n)) cout<<"Given number is Strong number"<<endl;
    else cout<<"Given number is not strong number"<<endl;

    return 0;
}