#include<bits/stdc++.h>
using namespace std;

void removeDuplicate(vector<int> &vec){
    map<int, bool> visited;
    int wI = 0;

    for(int rI=0; rI<vec.size(); rI++){
        if(!visited[vec[rI]]){
            visited[vec[rI]] = true;
            vec[wI] = vec[rI];
            wI++;
        }
    }

    vec.resize(wI);
}

int main(){
    vector<int> vec = {1, 2, 3, 4, 5, 1, 2, 4};

    removeDuplicate(vec);

    for(auto i : vec) cout<<i<<" ";

    return 0;
}