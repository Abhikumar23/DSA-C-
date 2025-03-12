#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int minSubArrayLen(int S, vector<int>& nums) {
    int n = nums.size();
    int left = 0, windowSum = 0, minLen = INT_MAX;

    for (int right = 0; right < n; right++) {
        windowSum += nums[right]; // Expand window

        while (windowSum >= S) { // Shrink window
            minLen = min(minLen, right - left + 1);
            windowSum -= nums[left];
            left++;
        }
    }

    return (minLen == INT_MAX) ? 0 : minLen;
}

int main() {
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    int S = 7;
    cout << "Smallest Subarray Length: " << minSubArrayLen(S, nums) << endl; // Output: 2
    return 0;
}
