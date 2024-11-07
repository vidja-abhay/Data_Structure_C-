#include<bits/stdc++.h>
using namespace std;

int secondSmallest(vector<int> &vec, int k){
   
    priority_queue<int> pq;

    for(int i=0; i<k; i++){
        pq.push(vec[i]);
    }

    for(int i=k; i<vec.size(); i++){
        if(pq.top() > vec[i]){
            pq.pop();
            pq.push(vec[i]);
        }
    }

    return pq.top();
}

int secondLargest(vector<int> &vec, int k){
    
    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i=0; i<k; i++){
        pq.push(vec[i]);
    }

    for(int i=k; i<vec.size(); i++){
        if(pq.top() < vec[i]){
            pq.pop();
            pq.push(vec[i]);
        }
    }

    return pq.top();
}

int main(){
    int n;
    cout<<"Enter a size of a vector : "<<endl;
    cin>>n;

    vector<int> vec(n);

    for(int i=0; i<n; i++){
        cin>>vec[i];
    }

    int SecondSmallest = secondSmallest(vec, 2);
    int SecondLargest = secondLargest(vec, 2);

    cout<<"Second smallest element of a vector is : "<<SecondSmallest<<" and second largest element is : "<<SecondLargest;

    return 0;
}