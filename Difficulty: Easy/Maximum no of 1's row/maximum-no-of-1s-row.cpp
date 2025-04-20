//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
        int lower(vector<int> &arr){
            int count1 = 0 ;
            int l = 0 , h = arr.size()-1;
            int idx =INT_MAX;
            while(l <= h){
                 int mid=(l+h)/2;
                 if(arr[mid] ==1) {
                     idx = min(idx,mid);
                     h = mid-1;
                 } 
                 else l = mid+1;
            }
            return arr.size()-idx;
        }
        int maxOnes (vector <vector <int>> &Mat, int N, int M)
        {
            // your code here
            int idx = -1;
            int cnt = -1;
            for(int i = 0 ; i < N ; i++){
                   int cnt1 = lower(Mat[i]);
                    
                    if(cnt1 > cnt) {
                        idx = i;
                         cnt = cnt1;
                     }
            }
            return idx;  //o(N * LOG(M))
        }
};


//{ Driver Code Starts.

int main(){
    int t; cin >> t;
    while (t--){
        int n, m; cin >> n >> m;
        vector <vector <int>> arr (n, vector <int> (m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> arr[i][j];
        Solution ob;        
        cout << ob.maxOnes(arr, n, m) << endl;
    
cout << "~" << "\n";
}
}
// } Driver Code Ends