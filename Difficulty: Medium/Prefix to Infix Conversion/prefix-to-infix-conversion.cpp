//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string preToInfix(string exp) {
        // Write your code here
         int i = exp.length()-1 ;
        stack<string>st;
        
        while(i >=0){
            
             if((exp[i] >= 'A' && exp[i] <= 'Z') || (exp[i] >= 'a' && exp[i] <= 'z') ){
                
                string oper(1 , exp[i]);//convert char to striing
                st.push(oper);
            }
            else{ //for operator
                string t1 = st.top();
                st.pop();
                string t2 = st.top();
                st.pop();
                
                
                st.push("(" + t1 + exp[i] + t2 + ")");
            }
            i--;
        }
        return st.top();
    }
};

//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string prefix;
        cin >> prefix;

        Solution obj;
        cout << obj.preToInfix(prefix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends