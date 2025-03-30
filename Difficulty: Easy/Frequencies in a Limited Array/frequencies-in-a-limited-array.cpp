//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> frequencyCount(vector<int>& arr) {
        int n = arr.size();
        vector<int> result(n, 0); // Initialize with 0 (correct default)
        unordered_map<int, int> mpp;

        // Count occurrences of numbers in range [1, n]
        for (int i = 0; i < n; i++) {
           
                mpp[arr[i]]++;
            
        }

        // Fill result array using the frequency map
        for (int i = 1; i <= n; i++) {
            result[i - 1] = mpp[i]; // Assign frequency to corresponding index
        }

        return result;
    }
};



//{ Driver Code Starts.

int main() {
    int t; // Number of test cases
    cin >> t;
    cin.ignore(); // Ignore the newline after the integer input
    while (t--) {
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num); // Read the array elements from input string

        Solution obj;
        vector<int> result = obj.frequencyCount(a);

        // Print the result in the required format
        if (result.empty()) {
            cout << "[]"; // Print empty brackets if no duplicates are found
        } else {
            for (int i = 0; i < result.size(); i++) {
                if (i != 0)
                    cout << " ";
                cout << result[i];
            }
        }
        cout << endl; // Ensure new line after each test case output
    }

    return 0;
}

// } Driver Code Ends