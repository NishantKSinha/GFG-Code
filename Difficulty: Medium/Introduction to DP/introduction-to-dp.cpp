//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    // Top-Down Approach (Memoization)
    long long int topDownHelper(int n, vector<long long int>& dp) {
        // Base cases
        if (n <= 1) return n;

        // Check if already computed
        if (dp[n] != -1) return dp[n];

        // Recursive computation with memoization
        return dp[n] = (topDownHelper(n - 1, dp) + topDownHelper(n - 2, dp))%1000000007;
    }

    long long int topDown(int n) {
        // code here
        vector<long long int>dp(n+1,-1);
         return topDownHelper(n, dp); 
        
    }
    long long int bottomUp(int n) {
        // code here
        vector<long long int>dp(n+1,-1);
         dp[0] = 0 ;
         dp[1] = 1;
        for(int i = 2 ; i <= n ; i++){
            dp[i] = (dp[i-1] + dp[i-2])%1000000007;
        }
        return dp[n];
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        long long int topDownans = obj.topDown(n);
        long long int bottomUpans = obj.bottomUp(n);
        if (topDownans != bottomUpans) cout << -1 << "\n";
        cout << topDownans << "\n";
    
cout << "~" << "\n";
}
}
// } Driver Code Ends