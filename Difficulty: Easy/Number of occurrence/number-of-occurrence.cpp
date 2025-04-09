//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  int lowerbound(vector<int> arr,int n , int x){
        //tc == 2 * o(log n)==> 2 bcz one for upperbound find and another for lowerbound find 
        int mid  = -1 ;
        int ans = n ;
       int l = 0;
        int r = n-1;
        while(l <= r){
            int mid = (r+l)/2;
            if(arr[mid] >= x){ 
                ans = mid;
                r = mid - 1;
                
            }
            else { 
                l = mid+1;
                
             }
           
        }
        return ans;
    }
    int upperbound(vector<int> arr,int n, int x){
        int mid  = -1 ;
        int ans = n ;
       int l = 0;
        int r = n-1;
        while(l <= r){
            int mid = (r+l)/2;
            if(arr[mid] > x){ 
                ans = mid;
                r = mid - 1;
                
            }
            else { 
                l = mid+1;
                
             }
           
        }
        return ans;
    }
	
    int countFreq(vector<int>& arr, int target) {
        // code here
         // code here
         int n = arr.size();
         int x = target;
	    int lower= lowerbound(arr ,n,  x); 
        int upper = upperbound(arr ,n, x);

        if(lower == n || arr[lower] != x) {
            return 0 ;
        }
       
        return {upper-1-lower+1};
        
    }
};



//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.countFreq(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends