#include<bits/stdc++.h>
using namespace std;

int getIndex(vector<int> v, int K) 
{ 
    auto it = find(v.begin(), v.end(), K); 

    if (it != v.end())  
    { 
        int index = it - v.begin(); 
        return index; 
    } 
    else { 
        return -1; 
    } 
} 

vector<int> replaceElementByRank(vector<int> &vec){
    vector<int> second = vec;
    vector<int> ans(vec.size());
    sort(second.begin(), second.end());

    for(int i=0; i<vec.size(); i++){
        int index = getIndex(second, vec[i]);
        ans[i] = index + 1;
    }

    return ans;
}

vector<int> replaceElementByRankUsingMap(vector<int> &vec){
    map<int, int> rank;

    for(int i=0; i<vec.size(); i++){
        rank[vec[i]] = i+1;
    }

    vector<int> ans;

    for(auto i : rank){
        ans.push_back(i.second);
    }

    return ans;
}

int main(){
    vector<int> vec = {20, 15, 26, 2, 98, 6};

    vector<int> rank = replaceElementByRankUsingMap(vec);

    for(auto i : rank) cout<<i<<" ";

    return 0;
}