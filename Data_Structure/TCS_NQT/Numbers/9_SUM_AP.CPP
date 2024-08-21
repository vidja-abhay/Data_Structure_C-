#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,a,d;
    cout<<"Enter total number in AP series : ";
    cin>>n;
    cout<<"Enter a first number in AP series : ";
    cin>>a;
    cout<<"Enter a difference between two number in AP series : ";
    cin>>d;

    int ans = (n/2) * (2*a + (n-1)*d);

    cout<<ans;

    return 0;
}