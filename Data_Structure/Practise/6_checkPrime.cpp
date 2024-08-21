#include<bits/stdc++.h>
using namespace std;

bool check(int n){
    for(int i=2;i<n;i++){
        if(n%i == 0){
            return false;
        }
    }
    
    return n > 1;
}

bool isPrime(int num) {
    if (num <= 1) return false;
    if (num <= 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;
    for (int i = 5; i <= sqrt(num); i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return false;
    }
    return true;
}

int main(){
    int n; cin>>n;
    
    if(check(n)){
        cout<<"prime";
    }
    else{
        cout<<"Not";
    }
    return 0;
}