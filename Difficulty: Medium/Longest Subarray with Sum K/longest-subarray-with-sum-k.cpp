//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        int target = k ;
        unordered_map<int,int>mpp; //locate sum with index
        int sum = 0 ;
        int maxlen = 0 ;
        
        for(int i = 0 ; i < arr.size();i++){
            sum = sum + arr[i];
            
            if(sum == target) maxlen = max(maxlen,i+1);
            
            int rem = sum - target;
            
            if(mpp.find(rem) != mpp.end()){ //in map it present
                maxlen = max(maxlen, i - mpp[rem]);
            }
            
        if(mpp.find(sum) == mpp.end() ){    //in map it not present //for shortest->if(mpp.find(sum) == mpp.end() || mpp.find(sum) !=mpp.end())
                
                mpp[sum] = i ;
            }
        }
        return maxlen;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution solution;
        cout << solution.longestSubarray(arr, k) << "\n";
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends