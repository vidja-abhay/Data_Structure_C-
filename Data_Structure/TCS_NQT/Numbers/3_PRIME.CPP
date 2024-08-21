#include<bits/stdc++.h>
using namespace std;

bool isPrime(int n){
    if(n <= 1) return false;
    if(n <= 3) return true;
    if(n%2 == 0 || n%3 == 0) return false;

    for(int i=5; i*i <= n; i+=6){
        if(n%i == 0 || n%(i+2) == 0){
            return false;
        }
    }

    return true;
}

int main(){
    int n;
    cout<<"Enter a number to check number is prime or not : ";
    cin>>n;

    if(isPrime(n)) cout<<"This number is Prime Number"<<endl;
    else cout<<"This number is not prime number"<<endl;

    return 0;
}