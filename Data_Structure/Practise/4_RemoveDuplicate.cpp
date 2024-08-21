#include<bits/stdc++.h>
using namespace std;

void removeDuplicate(vector<int> &a){
     map<int, bool> visited;
    vector<int> result;
    
    for(int i = 0; i < a.size(); i++) {
        if(visited[a[i]] == false) {
            visited[a[i]] = true;
            result.push_back(a[i]);
        }
    }
    
    a = result; 
}

void removeDuplicate2(vector<int> &a) {
    map<int, bool> visited;
    int writeIndex = 0;

    for (int readIndex = 0; readIndex < a.size(); readIndex++) {
        if (!visited[a[readIndex]]) {
            visited[a[readIndex]] = true;
            a[writeIndex] = a[readIndex];
            writeIndex++;
        }
    }

    a.resize(writeIndex);
}

int main(){
    vector<int> a;
    cout<<"Enter a size of vector : "<<endl;
    int n; cin>>n;
    cout<<"Enter an element into vector : "<<endl;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        a.push_back(x);
    }
    removeDuplicate2(a);
    for(int i : a){
        cout<<i<<" ";
    }
    return 0;
}