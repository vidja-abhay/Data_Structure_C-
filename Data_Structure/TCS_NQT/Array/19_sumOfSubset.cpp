#include <bits/stdc++.h>
using namespace std;

// Function to find a continuous sub-array which adds up to
// a given number.
vector<int> subarraySum(vector<int> arr, int sum)
{
    // To store the result
    vector<int> res;
    int n = arr.size();

    // Pick a starting point for a 
    // subarray
    for (int s = 0; s < n; s++)
    {
        int curr = 0;
      
        // Consider all ending points
        // for the picked starting point 
        for (int e = s; e < n; e++)
        {
            curr += arr[e];
            if (curr == sum)
            {
                res.push_back(s + 1);
                res.push_back(e + 1);
                return res;
            }
        }
    }
    return {-1}; // If no subarray is found
}

// Driver Code
int main()
{
    vector<int> arr = {15, 2, 4, 8, 9, 5, 10, 23};
    int sum = 23;
    vector<int> result = subarraySum(arr, sum);
    for (auto i : result)
        cout << i << " ";
    return 0;
}


// Input: arr[] = { 15, 2, 4, 8, 9, 5, 10, 23}, sum = 23
// Output: 2 5