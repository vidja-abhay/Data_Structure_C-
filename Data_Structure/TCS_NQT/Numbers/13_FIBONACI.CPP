#include<bits/stdc++.h>
using namespace std;

void fibonaci(int n){
    int first = 0;
    int second = 1;
    int next;
    
    cout<<first<<" "<<second<<" ";
    
    for(int i=2; i<=n; i++){
        next = first + second;
        first = second;
        second = next;
        cout<<next<<" ";
    }
}

int main(){
    int n; cin>>n;
    fibonaci(n);
    return 0;
}