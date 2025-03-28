//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isPrime(int n) {
        // code here
       if(n==1) return false;
        int cnt = 0;
        for(int i = 2 ; i <= n/2 ; i++){
            if(n % i == 0){
                cnt++;
            }
        }
        if(cnt == 0) return true;
        return false;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << (ob.isPrime(N) ? "true" : "false") << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends