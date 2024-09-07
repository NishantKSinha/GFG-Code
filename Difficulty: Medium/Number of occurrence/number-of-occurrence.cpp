//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int lowerbound(int arr[],int n , int x){
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
    int upperbound(int arr[],int n, int x){
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
        return ans-1;
    }
	int count(int arr[], int n, int x) {
	    // code here
	    int lower= lowerbound(arr ,n,  x); 
        int upper = upperbound(arr ,n, x);

        if(lower == n || arr[lower] != x) {
            return 0 ;
        }
       
        return {upper-lower+1};
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends