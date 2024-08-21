#include<bits/stdc++.h>
using namespace std;

bool isPrime(int n){
    if(n <= 1) return false;
    if(n <= 3) return true;
    if(n % 2 == 0 || n % 3 == 0) return false; // This line was incorrect

    for(int i = 5; i * i <= n; i += 6){
        if(n % i == 0 || n % (i + 2) == 0) return false;
    }
    
    return true;
}

int main(){
    int n;
    cin >> n;
    
    int x;
    bool flag = false;
    
    for(int i = 2; i <= n/2; i++){
        if(isPrime(i) && isPrime(n-i)){
            flag = true;
            x = i;
            break;
        }
    }
    
    if(flag){
        cout << "First Number : " << x << " Second Number : " << n-x;
    }
    else{
        cout << "no";
    }
    
    return 0;
}

// C++ Program to check whether a number be expressed as a sum of two prime numbers