//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int countAtMostK(string& s , int k)
    {
        if(k == 0) return 0;
        map<char , int> mpp ;
        int left = 0 , right = 0 , cnt = 0 , dist = 0;
        
        while(right < s.length()){
            
            if(mpp[s[right]] == 0) dist++;
            mpp[s[right]]++;
            
            while(dist> k)
            {
                mpp[s[left]]--;
                if(mpp[s[left]] == 0)dist--;
                left++;
            }
            
            cnt += (right - left + 1);
            right++;
        }
        
        return cnt;
        
    }
    int countSubstr(string& s, int k) {
        
        return countAtMostK(s , k) - countAtMostK(s , k - 1);
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.countSubstr(s, k) << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends