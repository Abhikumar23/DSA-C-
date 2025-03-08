#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string expandAroundCenter(string s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;  // Expand left
            right++; // Expand right
        }
        return s.substr(left + 1, right - left - 1); // Extract the palindrome
    }

    string longestPalindrome(string s) {
        if (s.empty())
            return "";

        string longest = "";
        for (int i = 0; i < s.size(); i++) {
            string odd = expandAroundCenter(s, i, i); // Odd-length palindrome
            string even = expandAroundCenter(s, i, i + 1); // Even-length palindrome

            if (odd.size() > longest.size())
                longest = odd;
            if (even.size() > longest.size())
                longest = even;
        }
        return longest;
    }
};

// **Driver Code**
int main() {
    Solution sol;
    string s;
    
    cout << "Enter a string: ";
    cin >> s;

    string result = sol.longestPalindrome(s);
    cout << "Longest Palindromic Substring: " << result << endl;

    return 0;
}
