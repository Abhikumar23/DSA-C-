#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solve(string expression, unordered_map<string, vector<int>>& dp) {
    if (dp.count(expression)) return dp[expression];

    vector<int> ans;

    for (int i = 0; i < expression.size(); ++i) {
        char c = expression[i];

        if (c == '+' || c == '-' || c == '*') {
            string leftPart = expression.substr(0, i);
            string rightPart = expression.substr(i + 1);

            vector<int> left = solve(leftPart, dp);
            vector<int> right = solve(rightPart, dp);

            for (int l : left) {
                for (int r : right) {
                    if (c == '+') ans.push_back(l + r);
                    else if (c == '-') ans.push_back(l - r);
                    else if (c == '*') ans.push_back(l * r);
                }
            }
        }
    }

    if (ans.empty()) {
        ans.push_back(stoi(expression));  // Base case: number only
    }

    dp[expression] = ans;  // Store result
    return ans;
}

vector<int> diffWaysToCompute(string expression) {
    unordered_map<string, vector<int>> dp;
    return solve(expression, dp);
}

int main() {
    // Test Case 1
    string expr1 = "2-1-1";
    vector<int> result1 = diffWaysToCompute(expr1);
    cout << "Possible results for \"" << expr1 << "\": ";
    for (int num : result1) cout << num << " ";
    cout << endl;

    // Test Case 2
    string expr2 = "2*3-4*5";
    vector<int> result2 = diffWaysToCompute(expr2);
    cout << "Possible results for \"" << expr2 << "\": ";
    for (int num : result2) cout << num << " ";
    cout << endl;

    return 0;
}
