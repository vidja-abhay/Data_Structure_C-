#include<bits/stdc++.h>
using namespace std;

int binary(int a[] , int key){
    int low =  0;
    int high = sizeof(a) / sizeof(a[0]) - 1;

    while(low < high){
        int mid = (low+high)/2;

        if(a[mid] == key){
            return mid;
        }

        else if(a[mid] > key){
            high = mid - 1;
        }

        else {
            low = mid;
        }
    }

    return 0;
}

int main(){
    int n; cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        int x; cin>>x;
        a[i] = x;
    }

    int key; cin>>key;

    int index = binary(a,key);

    cout<<index;
    return 0;
}