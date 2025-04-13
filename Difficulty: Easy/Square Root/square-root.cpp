//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// Function to find square root
// x: element to find square root
class Solution {
  public:
    int floorSqrt(int n) {
        // Your code goes here
        int l =1;
        int h = n/2;
        if(n==1) return 1;
        int ans = -1;
        while(l <= h){
            int mid = (l+h)/2;
            if(mid*mid <= n){
                ans = mid;
                l = mid+1;
                
            }
            else{
                h = mid-1;
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
        int n;
        cin >> n;
        Solution obj;
        cout << obj.floorSqrt(n) << endl;
    }
    return 0;
}

// } Driver Code Ends