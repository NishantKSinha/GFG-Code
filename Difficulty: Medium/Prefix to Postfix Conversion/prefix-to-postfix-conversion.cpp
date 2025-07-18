// User function Template for C++

class Solution {
  public:
    string preToPost(string exp) {
          stack<string>st;
        for(int i = exp.size()-1 ; i >= 0;i--){
            char ch = exp[i];
            if(ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z' || ch >= '1' &&ch <= '9'){
                st.push(string(1,ch));
            }
            else{
                string t1 = st.top(); st.pop();
                string t2 = st.top(); st.pop();
                string t3 =  t1 + t2 + ch;
                st.push(t3);
            }
        }
        return st.top();
    }
};