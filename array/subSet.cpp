#include <iostream>
#include <vector>
using namespace std;

// Function to generate all subsets using backtracking
void backtrack(vector<int>& nums, vector<int>& subset, int index, vector<vector<int>>& result) {
    result.push_back(subset); // Add current subset to the result

    for (int i = index; i < nums.size(); ++i) {
        subset.push_back(nums[i]); // Include nums[i] in the subset
        backtrack(nums, subset, i + 1, result); // Recur for next elements
        subset.pop_back(); // Remove nums[i] (Backtrack)
    }
}

// Function to return all subsets of nums
vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> subset;
    backtrack(nums, subset, 0, result);
    return result;
}

// Driver code
int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // Generate subsets
    vector<vector<int>> result = subsets(nums);

    // Print subsets
    cout << "Subsets:\n";
    for (auto& subset : result) {
        cout << "{ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "}\n";
    }

    return 0;
}
