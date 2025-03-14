#include <bits/stdc++.h>
using namespace std;

bool find132pattern(vector<int>& nums) {
    int n = nums.size();
    if (n < 3) return false; // A valid pattern requires at least 3 elements

    stack<int> st;  // Monotonic stack to track possible nums[j] values
    int num_k = INT_MIN;  // This will store the maximum valid nums[k]

    // Traverse from right to left
    for (int i = n - 1; i >= 0; i--) {
        // If we find nums[i] < num_k, we found the pattern
        if (nums[i] < num_k) return true;

        // Maintain the decreasing stack: Find the largest possible nums[k]
        while (!st.empty() && nums[i] > st.top()) {
            num_k = st.top();
            st.pop();
        }

        // Push current element as a possible nums[j]
        st.push(nums[i]);
    }
    return false;
}

int main() {
    vector<int> nums1 = {1, 2, 3, 4};
    vector<int> nums2 = {3, 1, 4, 2};

    cout << (find132pattern(nums1) ? "true" : "false") << endl; // Output: false
    cout << (find132pattern(nums2) ? "true" : "false") << endl; // Output: true
}
