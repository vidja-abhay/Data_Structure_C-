#include<bits/stdc++.h>
using namespace std;

int maxSubArraySum(vector<int>& nums) {
    int maxSoFar = nums[0];
    int maxEndingHere = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        maxEndingHere = max(nums[i], maxEndingHere + nums[i]);
        maxSoFar = max(maxSoFar, maxEndingHere);
    }

    return maxSoFar;
}

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    int maxSum = maxSubArraySum(nums);
    cout << "Maximum sum of a contiguous subarray is: " << maxSum << endl;

    return 0;
}
