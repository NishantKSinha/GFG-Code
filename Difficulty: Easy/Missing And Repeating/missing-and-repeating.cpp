//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
     unordered_map<int,int>mpp;
     int missing = -1 , repeat = -1;
     for(int i = 0 ; i < arr.size();i++){
         mpp[arr[i]]++;
     }
     for(int i = 1 ; i <= arr.size();i++){
         if(mpp.find(i) == mpp.end()) missing = i;
     }
     for(auto it : mpp){
         if(it.second == 2 ) repeat = it.first;
     }
     
     return{repeat,missing};
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