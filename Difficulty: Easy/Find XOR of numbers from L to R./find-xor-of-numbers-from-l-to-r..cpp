//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int fun1(int N){
        if(N%4 == 0) return N;
        else if(N%4==1) return 1;
        else if(N%4 == 2) return N+1;
        else return 0;
    }
    int findXOR(int l, int r) {
        // complete the function here
        return fun1(l-1) ^ fun1(r);
    }
};

//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    while (t--) {
        // Input

        int l, r;
        cin >> l >> r;

        Solution obj;
        cout << obj.findXOR(l, r) << endl;
    }
}
// } Driver Code Ends