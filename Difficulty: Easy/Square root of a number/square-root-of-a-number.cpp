//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution {
  public:
    long long int floorSqrt(long long int n) {
        // Your code goes here
         int low = 1, high = n;
         long long int ans =1;
         
    //Binary search on the answers:
    while (low <= high) {
        long long int mid = (low + high) / 2;
        long long int val = mid * mid;
        if (val <= n) {
            //eliminate the left half:
            low = mid + 1;
            ans = mid;
        }
        else {
            //eliminate the right half:
            high = mid - 1;
        }
    }
    return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        Solution obj;
        cout << obj.floorSqrt(n) << endl;
    }
    return 0;
}

// } Driver Code Ends