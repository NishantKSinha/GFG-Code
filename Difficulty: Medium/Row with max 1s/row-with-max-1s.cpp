//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int rowWithMax1s(vector<vector<int> > &arr) {
        // code here
        int rows = arr.size();
        int cols = arr[0].size();
        int index = -1;
        int maxi = 0;
        for(int row = 0 ; row < rows;row++){
            int sum = 0;
            for(int col = 0; col < cols;col++){
                sum = sum + arr[row][col];
            }
            if(sum > maxi){
                maxi = sum;
                index = row;
            }
        }
        return index;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > arr(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends