#include <iostream>
#include <vector>

using namespace std;

int findEquilibriumIndex(vector<int>& nums) {
    int totalSum = 0, leftSum = 0;
    
    for (int num : nums) totalSum += num; // Compute total sum

    for (int i = 0; i < nums.size(); i++) {
        if (leftSum == totalSum - leftSum - nums[i]) 
            return i; // Found equilibrium index
        leftSum += nums[i];
    }
    
    return -1; // No equilibrium index found
}

int main() {
    vector<int> nums = {1, 7, 3, 6, 5, 6};
    cout << "Equilibrium Index: " << findEquilibriumIndex(nums) << endl; // Output: 3
    return 0;
}
