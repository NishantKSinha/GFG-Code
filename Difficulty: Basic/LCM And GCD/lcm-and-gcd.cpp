//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> lcmAndGcd(int a, int b) {
        // code here
        vector<int>result;
        int temp = 0;
        int temp1 = 0;
        if(a < b){
          temp = a;
          temp1 = b;
        } 
        else{
          temp = b;
          temp1 = a;
        } 
        
        int ans1 = 0;
        int ans = 0;
        
        for(int i = 1 ; i <= temp1;i++){
            if((temp1* i) % temp == 0 ) {
                 ans =temp1 * i;
                 result.push_back(ans);
                break;
            }
        }
        
        for(int i = temp ; i> 0;i--){
            if(a % i == 0 && b % i == 0) {
                ans1 = i;
                result.push_back(ans1);
                break;
            }
        }
     
      return result;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int A, B;

        cin >> A >> B;

        Solution ob;
        vector<int> ans = ob.lcmAndGcd(A, B);
        cout << ans[0] << " " << ans[1] << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends