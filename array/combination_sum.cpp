#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve(vector<int>& candidates, int target, vector<vector<int>>& result,
           vector<int>& ans, int start) {
    if (target == 0) {
        result.push_back(ans);
        return;
    }
    for (int i = start; i < candidates.size(); i++) {
        if (candidates[i] > target) {
            break;
        }
        ans.push_back(candidates[i]);
        solve(candidates, target - candidates[i], result, ans, i);
        ans.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    vector<int> ans;
    sort(candidates.begin(), candidates.end());
    solve(candidates, target, result, ans, 0);
    return result;
}

int main() {
    vector<int> candidates = {2, 3, 6, 7};  // Example input
    int target = 7;

    vector<vector<int>> result = combinationSum(candidates, target);

    cout << "Combinations that sum to " << target << " are:\n";
    for (const auto& combination : result) {
        cout << "[ ";
        for (int num : combination) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}
