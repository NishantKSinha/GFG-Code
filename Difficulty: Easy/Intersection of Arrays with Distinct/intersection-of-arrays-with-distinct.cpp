//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

// User function template for C++

// Function to return the count of the number of elements in
// the intersection of two arrays.

class Solution {
  public:
    int numberofElementsInIntersection(vector<int> &a, vector<int> &b) {
        // Your code goes here
        int cnt = 0;
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        int i = 0,j=0;
        while(i < a.size() && j < b.size() ){
            if(a[i] == b[j]){
                cnt++;
                i++;
                j++;
            }
            else if(a[i] < b[j]){
                i++;
            }
            else j++;
        }
        return cnt;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr1, arr2;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr1.push_back(number);
        }

        // Read second array
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            arr2.push_back(number);
        }

        Solution ob;
        int res = ob.numberofElementsInIntersection(arr1, arr2);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends