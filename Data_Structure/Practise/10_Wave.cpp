#include<bits/stdc++.h>
using namespace std;

void wave(vector<int> &vec) {
    for (int i = 0; i < vec.size() - 1; i += 2) {
        // Swap if current element is greater than next (even index)
        if (vec[i] < vec[i + 1]) {
            swap(vec[i], vec[i + 1]);
        }
    }
}


int main(){
    int size; cin>>size;
    vector<int> vec(size);
    for(int i=0;i<size;i++){
        cin>>vec[i];
    }
    wave(vec);
    for(int i : vec){
        cout<<i<<" ";
    }
    return 0;
}