#include<bits/stdc++.h>
using namespace std;

int main(){
    float n,a,r;
    cout<<"Enter total number in AP series : ";
    cin>>n;
    cout<<"Enter a first number in AP series : ";
    cin>>a;
    cout<<"Enter a ratio between two number in AP series : ";
    cin>>r;

    float ans = a * ((1 - pow(r,n)) / (1-r));

    cout<<ans;
}