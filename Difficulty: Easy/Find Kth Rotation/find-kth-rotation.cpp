//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int count =0;
        int l = 0;
        int h = arr.size()-1;
        while(l<=h){
            int mid = (l+h)/2;
           
            if(arr[mid] > arr[h] ) {
                count = count + (mid-l+1);
                l = mid+1;
            }
             if(arr[mid] <= arr[h] && arr[l] > arr[mid]){
                
                 l++;
                 count = count + 1;
            }
            if(arr[mid] <= arr[h] && arr[l] <= arr[mid]){
                h = mid -1;
            }
        }
        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr.push_back(number1);
        }
        Solution ob;
        int res = ob.findKRotation(arr);
        cout << res << endl;
    }
}
// } Driver Code Ends