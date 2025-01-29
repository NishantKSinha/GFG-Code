//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int func(int idx , int target,vector<int>&arr,vector<int>&val,vector<vector<int>>&dp){
       //base-case == we are going deep to check whether there is any zero elements
       
        if(idx == 0){
         return (target/arr[0]) * val[0]; //if target is smaller then it automatically
                                          //return 0 bcz quotient come 0
            
       }
       
       
       if(dp[idx][target] != -1) return dp[idx][target];
       
       int nottake = func(idx-1,target,arr,val,dp); //simply call the main fumction
       int take = -1e9; // if we can't take the taken part bcz target become smaller than
                          //idx value direct return false and no further call will occur
       if(arr[idx] <= target) {
           take = val[idx] + func(idx,target-arr[idx],arr,val,dp);
       }
       return dp[idx][target] = max (take , nottake);
    }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
         int n = wt.size();
        vector<vector<int>>dp(n,vector<int>(capacity+1,-1));
        int ans = func(n-1,capacity,wt,val,dp);
        
        return ans ;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int W;
        cin >> W;
        cin.ignore();
        string str;
        getline(cin, str);
        stringstream ss(str);
        vector<int> val;
        int num;
        while (ss >> num) {
            val.push_back(num);
        }
        string str2;
        getline(cin, str2);
        stringstream ss2(str2);
        vector<int> wt;
        int num2;
        while (ss2 >> num2) {
            wt.push_back(num2);
        }
        Solution ob;
        cout << ob.knapSack(val, wt, W) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends