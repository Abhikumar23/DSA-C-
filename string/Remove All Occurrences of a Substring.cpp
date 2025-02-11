#include <iostream>
#include <stack>
using namespace std;

string removeOccurrences(string s, string part) {
    stack<char> st;
    int partLen = part.length();

    for (char ch : s) {
        st.push(ch);

        // Check if the top of the stack forms the substring "part"
        if (st.size() >= partLen) {
            string temp = "";
            for (int i = 0; i < partLen; i++) {
                temp = st.top() + temp;
                st.pop();
            }
            // If the substring doesn't match "part", push back the characters
            if (temp != part) {
                for (char c : temp) {
                    st.push(c);
                }
            }
        }
    }

    // Construct the final string from stack
    string result = "";
    while (!st.empty()) {
        result = st.top() + result;
        st.pop();
    }
    return result;
}

int main() {
    string s = "daabcbaabcbc";
    string part = "abc";
    cout << removeOccurrences(s, part) << endl;  // Output: "dab"
    return 0;
}
