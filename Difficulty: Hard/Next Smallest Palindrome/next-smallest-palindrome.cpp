//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    vector<int> generateNextPalindrome(int num[], int n) {
        vector<int> result(num, num + n);

        // Step 1: Mirror the left half to the right half
        for (int i = 0; i < n / 2; i++) {
            result[n - i - 1] = result[i];
        }

        // Step 2: Check if the mirrored number is greater or equal to the input
        bool isMirroredGreaterOrEqual = true;
        for (int i = 0; i < n; i++) {
            if (result[i] > num[i]) {
                isMirroredGreaterOrEqual = true;
                break;
            } else if (result[i] < num[i]) {
                isMirroredGreaterOrEqual = false;
                break;
            }
        }

        // If the mirrored number is greater, return it
        if (isMirroredGreaterOrEqual && result != vector<int>(num, num + n)) {
            return result;
        }

        // Step 3: Increment the middle part
        int carry = 1;
        int mid = n / 2;

        // For odd-length numbers, increment the exact middle digit
        if (n % 2 == 1) {
            result[mid] += carry;
            carry = result[mid] / 10;
            result[mid] %= 10;
        }

        // Increment the left part and propagate the carry
        for (int i = mid - 1; i >= 0; i--) {
            int sum = result[i] + carry;
            result[i] = sum % 10;
            carry = sum / 10;
        }

        // If there's a carry at the most significant digit, handle it
        if (carry) {
            result.insert(result.begin(), 1); // Add 1 at the beginning
            n = result.size();
        }

        // Mirror the left half to the right half again
        for (int i = 0; i < n / 2; i++) {
            result[n - i - 1] = result[i];
        }

        return result;
    }
};




//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int num[n];
        for (int i = 0; i < n; i++) {
            cin >> num[i];
        }
        Solution ob;
        auto ans = ob.generateNextPalindrome(num, n);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends