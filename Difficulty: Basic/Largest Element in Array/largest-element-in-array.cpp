//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    int largest(vector<int> &arr, int n)
    { 
        int ans;
        if(arr.size() == 1){
            ans = arr[0];
        }
        for(int i = 0 ; i < arr.size()-1;i++){
            if(arr[i + 1] >= arr[i]){
                ans = max(ans,arr[i+1]);
            }
            else{
                ans = max(ans,arr[i]);
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int>arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        cout << ob.largest(arr, n) << "\n";
    }
    return 0;
}

// } Driver Code Ends