//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
     
    void get(int num, int i){
        int ans = (num>>i)&1;
        cout<<ans<<" ";
    }
    
    void set(int num, int i){
        int ans = num|(1<<i);
        cout<<ans<<" ";
    }
    
    void clear(int num, int i){
        int ans = num&~(1<<i);
        cout<<ans<<" ";
    }
    void bitManipulation(int num, int i) {
        // your code here
         get(num, i-1);
        set(num, i-1);
        clear(num, i-1);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n >> i;
        Solution ob;
        ob.bitManipulation(n, i);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends