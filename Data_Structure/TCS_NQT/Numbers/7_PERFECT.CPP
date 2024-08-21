#include<bits/stdc++.h>
using namespace std;

bool isPerfect(int n){
    int sum = 0;

    for(int i=1; i<=n; i++){
        if(n%i == 0) sum += i;
    }

    return sum == 2*n;
}

int main(){
    int n;
    cout<<"Enter a number to check number is perfect or not : ";
    cin>>n;

    if(isPerfect(n)) cout<<"This number is perfect Number"<<endl;
    else cout<<"This number is not perfect number"<<endl;

    return 0;
}