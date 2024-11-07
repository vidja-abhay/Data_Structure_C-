// GIVEN AN ARRAY AND AN INTEGER 'K'. WE NEED TO FIND THE MAXIMUM ELEMENT IN EACH OF THE CONTIGUOUS SUBARRAY.
// I/P : {1, 4, 7, 1, 6, 3}, K = 3
// O/P : {7, 7, 7, 6}

#include<bits/stdc++.h>
using namespace std;



    vector<int> maxSlidingWindow(vector<int>& vec, int k) {
        vector<int> result;
        multiset<int> ms;

        int i = 0, j = 0;

        int size = vec.size();

        if(size < k) return {};

        while(j < size){
            ms.insert(vec[j]);

            if(j - i + 1 < k) j++;

            else if(j - i + 1 == k){
                result.push_back(*ms.rbegin());
                ms.erase(ms.find(vec[i]));
                i++;
                j++;
            }
        }

        return result;
    }


int main(){
    vector<int> vec = {1, 4, 7, 1, 6, 3};
    vector<int> res = maxSlidingWindow(vec, 3);
    for(auto i : res) cout<<i<<" ";
}