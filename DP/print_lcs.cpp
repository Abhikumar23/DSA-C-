#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string longestCommonSubsequence(string s1, string s2) {

    int n = s1.size();
    int m = s2.size();

    vector<vector<int> > dp( n + 1, vector<int>(m + 1, 0));


    for (int i = 1; i <= n; i++) {

        for (int j = 1; j <= m; j++) {

            if (s1[i - 1] == s2[j - 1]) {

                // Characters match
                dp[i][j] = 1 + dp[i - 1][j - 1];

            }
            else {

                // Characters don't match
                dp[i][j] = max(
                    dp[i - 1][j],
                    dp[i][j - 1]
                );
            }
        }
    }

    // RECONSTRUCT LCS
  
    string ans = "";

    int i = n;
    int j = m;

    while (i > 0 && j > 0) {

        // Characters match
        if (s1[i - 1] == s2[j - 1]) {

            ans.push_back(s1[i - 1]);

            i--;
            j--;
        }

        // Move upward
        else if (dp[i - 1][j] > dp[i][j - 1]) {

            i--;
        }

        // Move left
        else {

            j--;
        }
    }


    // We constructed the answer backwards
    reverse(ans.begin(), ans.end());

    return ans;
}


int main() {

    string s1;
    string s2;

    cout << "Enter first string: ";
    cin >> s1;

    cout << "Enter second string: ";
    cin >> s2;

    string ans = longestCommonSubsequence(s1, s2);

    cout << "Longest Common Subsequence: "
         << ans
         << endl;

    return 0;
}