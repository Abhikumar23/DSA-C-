#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    unordered_map<string, vector<int>> dp;  // Memoization map

    vector<int> solve(string expression) {
        if (dp.count(expression)) return dp[expression];

        vector<int> ans;

        for (int i = 0; i < expression.size(); ++i) {
            char c = expression[i];
            if (c == '+' || c == '-' || c == '*') {
                string leftPart = expression.substr(0, i);
                string rightPart = expression.substr(i + 1);

                vector<int> left = solve(leftPart);
                vector<int> right = solve(rightPart);

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
        return solve(expression);
    }
};

int main(){

}