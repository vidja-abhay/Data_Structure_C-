#include<bits/stdc++.h>
using namespace std;

void reverseArray(vector<int> &vec){
    int low = 0, high = vec.size()-1;

    while(low < high){
        int temp = vec[low];
        vec[low] = vec[high];
        vec[high] = temp;
        low++;
        high--; 
    }
}

int main(){
    int n;
    cout<<"Enter a size of a vector : "<<endl;
    cin>>n;

    vector<int> vec(n);

    for(int i=0; i<n; i++){
        cin>>vec[i];
    }

    // reverse(vec.begin(), vec.end());

    reverseArray(vec);

    for(auto i : vec) cout<<i<<" ";

    return 0;
}