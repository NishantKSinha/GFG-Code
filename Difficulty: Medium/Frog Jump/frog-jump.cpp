//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
   int minCostRec(int i, vector<int>& height,vector<int>&dp) {
        // Base case: If you've reached the last or second-to-last step, no more cost to move
        if (i ==0) return 0;  // If you go beyond the last step, no more cost
        
        if(dp[i] != -1) return dp[i];

        // Option 1: Move to the next step
        int cost1 = abs(height[i] - height[i - 1]) + minCostRec(i - 1, height,dp);
        
        // Option 2: Jump to the step after next (i-2), valid if i > 1
     int cost2 = INT_MAX;
      if(i > 1){
           cost2= abs(height[i] - height[i - 2]) + minCostRec(i - 2, height,dp) ;
      }
     
      
        // Return the minimum cost to move forward
        return dp[i] = min(cost1, cost2);
    }
    int minCost(vector<int>& height) {
        // Code here
        int indx = height.size()-1;
        vector<int>dp(indx+1,-1);
        
        return minCostRec(indx,height,dp);
    }
};

//{ Driver Code Starts.

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        cout << ob.minCost(arr) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends