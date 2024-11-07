#include<bits/stdc++.h>
using namespace std;

int minSubArraySum(vector<int>& nums) {
    int minSoFar = nums[0];
    int minEndingHere = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        minEndingHere = min(nums[i], minEndingHere + nums[i]);
        minSoFar = min(minSoFar, minEndingHere);
    }

    return minSoFar;
}

int main() {
    vector<int> nums = {3, -4, 2, -3, -1, 7, -5};

    int minSum = minSubArraySum(nums);
    cout << "Minimum sum of a contiguous subarray is: " << minSum << endl;

    return 0;
}
