//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int func(int k , int i , vector<int>&arr,vector<int>&dp){
        
        if(i==0) return 0;
        
        if(dp[i] != -1) return dp[i];
          int maxstep = INT_MAX;
        
        for(int j = 1 ; j <= k;j++ ){
            int jump = INT_MAX;
            
            if(i-j >= 0){
                jump = abs(arr[i] - arr[i - j]) + func(k,i - j, arr,dp);
            }
            maxstep = min(jump , maxstep);
        }
        return dp[i] =  maxstep;
    }
    int minimizeCost(int k, vector<int>& arr) {
        // Code here
      int indx = arr.size();
      vector<int>dp(indx , -1);
      return func(k,indx-1,arr,dp);
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minimizeCost(k, arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends