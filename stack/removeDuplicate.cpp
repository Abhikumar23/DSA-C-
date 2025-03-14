#include <bits/stdc++.h>
using namespace std;

string removeDuplicateLetters(string s) {
    unordered_map<char, int> freq;
    unordered_set<char> visited;
    stack<char> st;

    // Count frequency of each character
    for (char ch : s) freq[ch]++;

    for (char ch : s) {
        freq[ch]--;  // Decrease frequency

        // Skip if already in result
        if (visited.count(ch)) continue;

        // Maintain lexicographical order
        while (!st.empty() && st.top() > ch && freq[st.top()] > 0) {
            visited.erase(st.top());
            st.pop();
        }

        // Add current character
        st.push(ch);
        visited.insert(ch);
    }

    // Build result
    string result = "";
    while (!st.empty()) {
        result = st.top() + result;
        st.pop();
    }
    return result;
}

int main() {
    cout << removeDuplicateLetters("bcabc") << endl;     // Output: "abc"
    cout << removeDuplicateLetters("cbacdcbc") << endl;  // Output: "acdb"
}
