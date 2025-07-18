// User function Template for C++

class Solution {
  public:
    string postToInfix(string exp) {
        // Write your code here
        stack<string>st;
        for(int i = 0  ; i < exp.size();i++){
            char ch = exp[i];
            if(ch>= 'A' && ch >= 'Z' || ch>= 'a' && ch >= 'z' || ch>= '1' && ch >= '9'){
                st.push(string(1, ch));
            }
            else{
                string t1 = st.top(); st.pop();
                string t2 = st.top(); st.pop();
                string t3 = '(' + t2 + ch + t1 + ')';
                st.push(t3);
            }
        }
        return st.top();
    }
};