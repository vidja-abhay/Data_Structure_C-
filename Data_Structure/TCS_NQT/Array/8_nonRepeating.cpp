#include<bits/stdc++.h>
using namespace std;

vector<int> nonRepeating (vector<int> &vec){
    map<int, int> counted;
    vector<int> ans;

    for(int rI=0; rI<vec.size(); rI++){
        counted[vec[rI]]++;
    }

    for(auto i : counted){
        if(i.second == 1){
            ans.push_back(i.first);
        }
    }

    return ans;
}

int main(){
    vector<int> vec = {1, 2, 3, 4, 5, 1, 2, 4};

    vector<int> ans = nonRepeating(vec);

    for(auto i : ans) cout<<i<<" ";

    return 0;
}