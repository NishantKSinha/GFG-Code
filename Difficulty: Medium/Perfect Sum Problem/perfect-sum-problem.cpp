//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int func(int idx , int target,vector<int>&arr, vector<vector<int>>&dp){
       //base-case
       
    
       if(idx == 0){
           if(target == 0 && arr[0] == target) return 2;
           if(arr[0] == target || target == 0) return 1;
            else return 0;
       }
       
       
       if(dp[idx][target] != -1) return dp[idx][target];
       
       int nottake = func(idx-1,target,arr,dp); //simply call the main fumction
       int take = 0; // if we can't take the taken part bcz target become smaller than
                          //idx value direct return false and no further call will occur
       if(arr[idx] <= target) {
           take = func(idx-1,target-arr[idx],arr,dp);
       }
       return dp[idx][target] = (take + nottake);
   }
    int perfectSum(vector<int>& arr, int target) {
        // code here
         int n = arr.size();
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return func(n-1,target,arr,dp); 
    
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int target;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> target;
        cin.ignore(); // Ignore newline character after target input

        Solution solution;
        cout << solution.perfectSum(arr, target);
        cout << "\n~\n";
    }

    return 0;
}

// } Driver Code Ends