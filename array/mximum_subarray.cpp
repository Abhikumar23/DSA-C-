#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int maxSum = INT_MIN; // Initialize max sum as the smallest possible value
    int sum = 0; 

    for (int num : nums) {
        sum = max(num, sum + num); // Either start a new subarray or continue the existing one
        maxSum = max(maxSum, sum); // Update maxSum if the current sum is greater
    }

    return maxSum;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int result = maxSubArray(nums);
    cout << "Maximum Subarray Sum: " << result << endl;

    return 0;
}
