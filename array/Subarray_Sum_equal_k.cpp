#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int longestSubarrayWithSumK(vector<int>& nums, int K) {
    unordered_map<int, int> prefixMap; // Store (prefixSum, first index)
    int prefixSum = 0, maxLen = 0;

    for (int i = 0; i < nums.size(); i++) {
        prefixSum += nums[i];

        // If subarray from start gives sum K
        if (prefixSum == K) maxLen = i + 1;

        // If (prefixSum - K) exists in map, update maxLen
        if (prefixMap.find(prefixSum - K) != prefixMap.end()) {
            maxLen = max(maxLen, i - prefixMap[prefixSum - K]);
        }

        // Store first occurrence of prefixSum
        if (prefixMap.find(prefixSum) == prefixMap.end()) {
            prefixMap[prefixSum] = i;
        }
    }

    return maxLen;
}

int main() {
    vector<int> nums = {1, 2, 3, 7, 5};
    int K = 12;
    cout << "Longest Subarray Length: " << longestSubarrayWithSumK(nums, K) << endl; // Output: 4
    return 0;
}
