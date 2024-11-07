#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> vec = {1, 2, 3, 4, 5};
    reverse(vec.begin(), vec.end());

    if(vec.size()%2 != 0){
        cout<<vec[vec.size()/2];
    }

    else{
        cout << double((vec[vec.size()/2 - 1] + vec[vec.size()/2]) / 2);
    }
}