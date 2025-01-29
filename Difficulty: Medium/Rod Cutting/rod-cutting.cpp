//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
   int func(int idx , int target,vector<int>&arr,vector<vector<int>>&dp){
       //base-case == we are going deep to check whether there is any zero elements
       int currrodlength = idx+1;
        if(idx == 0){
         return (target/currrodlength) * arr[0]; //if target is smaller then 
                        // it automatically return 0 bcz quotient come 0
                                          
            
       }
       
       
       if(dp[idx][target] != -1) return dp[idx][target];
       
       int nottake = func(idx-1,target,arr,dp); //simply call the main fumction
       int take = -1e9; // if we can't take the taken part bcz target become smaller than
                          //idx value direct return false and no further call will occur
       if(currrodlength <= target) {
           take = arr[idx] + func(idx,target-currrodlength,arr,dp);
       }
       return dp[idx][target] = max (take , nottake);
    }
    int cutRod(vector<int> &price) {
        // code here
         int n = price.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        int ans = func(n-1,n,price,dp);
        
        return ans ;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;

        cout << ob.cutRod(a) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends