#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        int n = strs.size();
        string start = strs[0];
        string end = strs[n - 1];
        string ans = "";

        for (int i = 0; i < start.size(); i++) {
            if (start[i] == end[i]) {
                ans += start[i];
            } else {
                break;
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;
    vector<string> strs = {"flower", "flow", "flight"};
    string result = solution.longestCommonPrefix(strs);
    cout << "Longest Common Prefix: " << result << endl;

    return 0;
}
