//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    vector<long long> factorialNumbers(long long n) {
        // Write Your Code here
       
         vector<long long>result;
        return print(1 , n , 1,result);
    }
    
    
    vector<long long> print(int num ,long long n, long long sum,vector<long long>result){
          if (sum > n) return result;  // Base case: Stop when factorial exceeds n
    result.push_back(sum);        // Store the factorial number
    return print(num + 1, n, sum * (num + 1), result); // Recursive call
        
        
        
       
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        cin >> N;
        Solution ob;
        vector<long long> ans = ob.factorialNumbers(N);
        for (auto num : ans) {
            cout << num << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends