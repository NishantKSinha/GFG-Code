//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int a =-1;
        int b = -1;
        for(int i = 0 ; i < arr.size();i++){
            if(a < arr[i] && b == a) a = arr[i];
            else if(a < arr[i] && b < a) {
                b = a;
                a = arr[i];
                
            }
            else if(a > arr[i] && b < arr[i]) b = arr[i];          
        }
        return b;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int ans = ob.getSecondLargest(arr);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends