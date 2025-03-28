//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    int sumOfSeries(int n) {
        // code here
        long long sum = 0 ;
        return  print(n ,sum);
        
    }
    
    int print(int n, long long sum){
        if(n < 1) {
          //  cout << sum;
            return sum;
        }
     
       sum = sum + pow(n,3);
       
        print(n-1,sum);
        
       
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
        cout << ob.sumOfSeries(N) << "\n";

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends