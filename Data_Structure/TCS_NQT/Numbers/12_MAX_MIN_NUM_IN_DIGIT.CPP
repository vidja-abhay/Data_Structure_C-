#include<bits/stdc++.h>
using namespace std;

void maxMinNumberInDigit(int n){
    int mini = INT_MAX;
    int maxi = INT_MIN;
    int d;

    while(n > 0){
        d = n%10;
        mini = min(mini, d);
        maxi = max(maxi, d);

        n /= 10;
    }

    cout<<"Minimum digit of number is : "<<mini<<endl;
    cout<<"Maximum digit of number is : "<<maxi<<endl;
}

int main(){
    int n;
    cin>>n;

    maxMinNumberInDigit(n);

    return 0;
}