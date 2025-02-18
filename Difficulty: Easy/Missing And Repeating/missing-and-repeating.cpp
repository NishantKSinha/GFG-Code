//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        vector<int>ans;
        int missing = -1;
        int repeating = -1;
        
        unordered_map<int,int>mp;
        
           for(int j = 0 ; j < arr.size();j++){
                
                mp[arr[j]] ++;
            }
            
            for (int i = 1; i <= arr.size(); i++) {
        if (mp[i] == 2) repeating = i;  // Found the repeating number
        if (mp[i] == 0) missing = i;    // Found the missing number
        
        if (repeating != -1 && missing != -1) break;
    }
    
        return ans = {repeating , missing};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> arr;
        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        auto ans = ob.findTwoElement(arr);
        cout << ans[0] << " " << ans[1] << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends