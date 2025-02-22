//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int findMatching(string text, string pat) {
        // Code here
        int n = text.size();
        int m = pat.size();
        
        int i = 0; // Pointer for text
        int j = 0; // Pointer for pattern
        int k = 0; // Starting index for the current attempt

        while (i < n) {
            if (text[i] == pat[j]) {
                i++;
                j++;
            } else {
                // Reset search from the next character
                k++;
                i = k;
                j = 0;
            }

            // If we matched the entire pattern
            if (j == m) return k;
        }
        return -1; // Pattern not found
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string text, pat;
        cin >> text >> pat;
        Solution obj;
        cout << obj.findMatching(text, pat) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends