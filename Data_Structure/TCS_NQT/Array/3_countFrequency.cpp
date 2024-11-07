#include<bits/stdc++.h>
using namespace std;

map<int, int> countFrequency(vector<int> &vec){
    map<int, int> items;

    for(auto nums : vec){
        items[nums]++;
    }

    return items;
}

int main(){
    int n;
    cout<<"Enter a size of a vector : ";
    cin>>n;

    vector<int> vec(n);

    cout<<"Enter a element of vector : ";

    for(int i=0; i<n; i++) cin>>vec[i];

    map<int, int> countFrequencyMap = countFrequency(vec);

    for(auto i : countFrequencyMap){
        cout<< i.first <<"->" <<i.second<<endl;
    }

    return 0;
}