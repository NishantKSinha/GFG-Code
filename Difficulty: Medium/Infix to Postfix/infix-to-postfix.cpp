//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    int priority(char ch){
        
        if(ch == '^') return 3;
        else if(ch == '*' || ch == '/') return 2;
        else if(ch == '+' || ch == '-') return 1;
        else return -1;
    }
    string infixToPostfix(string s) {
        // Your code here
        int i = 0 ;
        string ans = "";
        stack<char>st;
        int n = s.size(); 
        while(i < n){
            
            if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || 
            (s[i] >= '0' && s[i] <= '9')){
                
                ans = ans+s[i];
            }
            
            else if(s[i] == '(') {
                st.push(s[i]);
            }
            
            else if(s[i] == ')'){
                while(!st.empty() && st.top() != '('){
                    ans = ans + st.top();
                    st.pop();
                }
                st.pop();
            }
            
            else{ //for priority of operators
               
                while(!st.empty() && priority(s[i]) <= priority(st.top())){
                    ans = ans + st.top();
                    st.pop();
                }
                st.push(s[i]);
                
            }
            i++;
        }
        while(!st.empty()){
            ans = ans + st.top();
            st.pop();
        }
        return ans;
    }
};


//{ Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}

// } Driver Code Ends