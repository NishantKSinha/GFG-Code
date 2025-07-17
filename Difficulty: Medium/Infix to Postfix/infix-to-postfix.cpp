class Solution {
  public:
  int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if(op == '^') return 3;
    return 0;
}
    string infixToPostfix(string& s) {
        // code here
        string ans ="";
        stack<char>st;
        for(int i =0 ; i < s.size();i++){
            if(s[i] != '+' && s[i] != '-' && s[i] != '*' && s[i] != '^' && s[i] != '(' && s[i] != ')' && s[i] != '/'){
                ans += s[i];
            }
            else{
                if(st.empty() || s[i] == '(') st.push(s[i]);
                else if(s[i] ==')'){
                    while(st.top() != '('){
                        char ch = st.top();
                        st.pop();
                        ans += ch;
                    }
                    st.pop();
                }
                else{
                    if (precedence(s[i]) > precedence(st.top())) {
                        st.push(s[i]);
                        
                    }
                    else{
                         while(!st.empty() && precedence(s[i]) <= precedence(st.top())){
                             ans = ans + st.top();
                              st.pop();
                           }
                           st.push(s[i]);
                    }
                    
                }
            }
        }
           while(!st.empty()){
            ans = ans + st.top();
            st.pop();
        }
        return ans;
    }
};
