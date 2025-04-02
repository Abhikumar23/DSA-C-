#include <iostream>
#include <vector>

using namespace std;

int helper(string& s, string& t, int i, int j, vector<vector<int>>& memo) {
    if (j == t.size()) {  // If we have matched the entire `t`
        return 1;
    }
    if (i == s.size()) {  // If `s` is exhausted but `t` is not
        return 0;
    }
    if (memo[i][j] != -1) {  // Return cached result
        return memo[i][j];
    }
    
    if (s[i] == t[j]) {
        // Either include `s[i]` or exclude it
        memo[i][j] = helper(s, t, i + 1, j + 1, memo) + helper(s, t, i + 1, j, memo);
    } else {
        // Skip `s[i]` if it doesn't match `t[j]`
        memo[i][j] = helper(s, t, i + 1, j, memo);
    }
    
    return memo[i][j];
}

int numDistinct(string s, string t) {
    vector<vector<int>> memo(s.size(), vector<int>(t.size(), -1));
    return helper(s, t, 0, 0, memo);
}

int main() {
    // Test Case 1
    string s1 = "rabbbit", t1 = "rabbit";
    cout << "Number of distinct subsequences: " << numDistinct(s1, t1) << endl;

    // Test Case 2
    string s2 = "babgbag", t2 = "bag";
    cout << "Number of distinct subsequences: " << numDistinct(s2, t2) << endl;

    return 0;
}
