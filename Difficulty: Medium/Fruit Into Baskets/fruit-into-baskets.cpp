//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int totalFruits(vector<int> &arr) {
        int l = 0 ;
        int r = 0 ;
        unordered_map<int , int > mpp;
        int ans = 0;
        
        while(r < arr.size()){
            mpp[arr[r]]++;
            while(mpp.size() > 2){
                
                  mpp[arr[l]]--;
                if(mpp[arr[l]] == 0) mpp.erase(arr[l]);
                l++;
                
            }
            ans = max(ans , r-l+1); 
            r++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore any newline character left in the buffer
    while (t--) {
        string line;
        getline(cin, line); // Read the entire line of input
        stringstream ss(line);
        vector<int> arr;
        int num;

        // Parse the input line into integers and add to the vector
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        int ans = ob.totalFruits(arr);

        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends