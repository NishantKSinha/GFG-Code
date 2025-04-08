//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User code template

class Solution {
  public:
    vector<int> getFloorAndCeil(int x, vector<int> &arr) {
        // code here
        sort(arr.begin(),arr.end());
         int i = 0 , j  = arr.size()-1;
        int lower = -1 , higher = INT_MAX;
        while(i <= j){
            int mid  = (i+j)/2;
            if(arr[mid] <= x){
                lower = max(lower,arr[mid]);
                i = mid +1;
            }
            else{
                j = mid-1;
            }
        }
         int k = 0 , l  = arr.size()-1;
        while(k <= l){
            int mid  = (k+l)/2;
            if(arr[mid] >= x){
                higher = min(higher,arr[mid]);
                l = mid -1;
            }
            else{
                k = mid+1;
            }
        }
        if(higher == INT_MAX) higher =-1;
        return{lower,higher};
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t
    while (t--) {
        vector<int> arr;
        int x;
        string input;
        cin >> x;
        cin.ignore();

        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        auto ans = ob.getFloorAndCeil(x, arr);
        cout << ans[0] << " " << ans[1] << "\n~\n";
    }
    return 0;
}
// } Driver Code Ends