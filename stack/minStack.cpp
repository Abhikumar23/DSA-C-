#include <iostream>
#include <stack>

using namespace std;

class MinStack {
    stack<int> s;
    stack<int> st; // Auxiliary stack for minimum values

public:
    MinStack() {
    }
    
    void push(int val) {
        s.push(val);
        if (st.empty() || st.top() >= val) {
            st.push(val);
        }
    }
    
    void pop() {
        if (s.empty()) return;
        if (s.top() == st.top()) {
            st.pop();
        }
        s.pop();
    }
    
    int top() {
        if (s.empty()) return -1; // Return -1 for empty stack
        return s.top();
    }
    
    int getMin() {
        if (st.empty()) return -1; // Return -1 for empty stack
        return st.top();
    }
};

// **Driver Code**
int main() {
    MinStack minStack;
    
    minStack.push(5);
    cout << "Pushed: 5, Min: " << minStack.getMin() << endl;
    
    minStack.push(3);
    cout << "Pushed: 3, Min: " << minStack.getMin() << endl;

    minStack.push(7);
    cout << "Pushed: 7, Min: " << minStack.getMin() << endl;

    minStack.push(2);
    cout << "Pushed: 2, Min: " << minStack.getMin() << endl;

    minStack.pop();
    cout << "Popped, Min: " << minStack.getMin() << endl;

    minStack.pop();
    cout << "Popped, Min: " << minStack.getMin() << endl;

    cout << "Top Element: " << minStack.top() << endl;
    
    return 0;
}
