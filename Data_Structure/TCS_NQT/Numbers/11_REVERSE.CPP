#include<bits/stdc++.h>
using namespace std;

int reverseNum(int n){
    int ans = 0;
    int temp = n;

    while(temp > 0){
        ans = ans*10 + temp%10;
        temp /= 10;
    }

    return ans;
}

int main(){
    int n; cin>>n;
    cout<<reverseNum(n);
    return 0;
}