#include <bits/stdc++.h>
using namespace std;

int solve(string &word1, string &word2, int i, int j, vector<vector<int>> &dp) {
    // Base cases
    if (i == word1.size()) return word2.size() - j; // Insert remaining characters
    if (j == word2.size()) return word1.size() - i; // Delete remaining characters

    if (dp[i][j] != -1) return dp[i][j]; // Use memoized result

    if (word1[i] == word2[j]) {
        return dp[i][j] = solve(word1, word2, i + 1, j + 1, dp); // No operation needed
    } else {
        // Insert
        int insertOp = 1 + solve(word1, word2, i, j + 1, dp);
        // Delete
        int deleteOp = 1 + solve(word1, word2, i + 1, j, dp);
        // Replace
        int replaceOp = 1 + solve(word1, word2, i + 1, j + 1, dp);

        return dp[i][j] = min({insertOp, deleteOp, replaceOp});
    }
}

// Driver function
int minDistance(string word1, string word2) {
    int n = word1.size(), m = word2.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return solve(word1, word2, 0, 0, dp);
}

int main() {
    string word1, word2;
    cout << "Enter first word: ";
    cin >> word1;
    cout << "Enter second word: ";
    cin >> word2;

    cout << "Minimum edit distance: " << minDistance(word1, word2) << endl;
    return 0;
}
