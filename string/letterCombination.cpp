#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void backtrack(string &digits, vector<string> &keypad,
                   int index, string current, vector<string> &result) {
        if (index == digits.length()) {
            result.push_back(current);
            return;
        }
        
        int digit = digits[index] - '0';
        string letters = keypad[digit];
        
        for (char letter : letters) {
            backtrack(digits, keypad, index + 1, current + letter, result);
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return {};
        
        vector<string> keypad = {
            "",     // 0
            "",     // 1
            "abc",  // 2
            "def",  // 3
            "ghi",  // 4
            "jkl",  // 5
            "mno",  // 6
            "pqrs", // 7
            "tuv",  // 8
            "wxyz"  // 9
        };
        
        vector<string> result;
        backtrack(digits, keypad, 0, "", result);
        return result; 
    }
};

int main() {
    Solution solution;
    string digits = "23";
    vector<string> result = solution.letterCombinations(digits);
    
    cout << "Letter Combinations: ";
    for (const string &combination : result) {
        cout << combination << " ";
    }
    cout << endl;
    
    return 0;
}
