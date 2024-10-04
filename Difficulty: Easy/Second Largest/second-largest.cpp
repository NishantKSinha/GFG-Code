//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    // Function returns the second
    // largest elements
    int getSecondLargest(vector<int> &arr) {
        // Code Here
        int min1 = arr[0];
        int min2 = -1;
        for(int i = 1; i < arr.size();i++){
            if(min1 < arr[i] ) {
                min2 = min1;
                min1 = arr[i];
                
            }
            if(min1 > arr[i] && min2 < arr[i]) {
                min2 = arr[i];
               
            }
        }
        return min2; 
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int ans = ob.getSecondLargest(arr);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends