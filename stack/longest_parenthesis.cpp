#include<iostream>
#include<stack>
#include<string>
using namespace std;

int longestValidParentheses(string s) {
    stack<int>st;
    st.push(-1);

    int maxLen=0;

    for(int i=0; i<s.size(); i++){
     
     if(s[i]=='('){
         st.push(i);
     }else{
         st.pop();
     }
     if(st.empty()){
         st.push(i);
     }else{
         int length= i-st.top();
         maxLen= max(maxLen, length);
     }
    }

return maxLen;
}

int main(){
    string s;
    cout<<"Enter the string:";
    cin>> s ;
    
    cout<< longestValidParentheses(s) << endl;
    

    return 0;
} 