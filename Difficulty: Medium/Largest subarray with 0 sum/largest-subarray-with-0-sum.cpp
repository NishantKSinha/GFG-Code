//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution {
  public:
    int maxLen(vector<int>& arr) {
        // code here
        int target = 0 ;
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
            
            if(mpp.find(sum) == mpp.end()){ //in map it not present
                
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
    cin.ignore(); // to ignore the newline after the integer input
    while (t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.maxLen(a) << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends