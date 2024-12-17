//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
         if (start == end) return 0;

    queue<pair<int, int>> q;  // {steps, node}
    q.push({0, start});
    
    int mod = 100000;  // Match the dist vector size
    vector<int> dist(mod, 1e9);  // Distance array initialized to "infinity"
    dist[start] = 0;

    while (!q.empty()) {
        int node = q.front().second;
        int steps = q.front().first;
        q.pop();

        for (auto it : arr) {
            int num = (1LL * it * node) % mod;  // Avoid overflow

            if (steps + 1 < dist[num]) {
                dist[num] = steps + 1;
                if (num == end) return steps + 1;  // Target reached
                q.push({steps + 1, num});
            }
        }
    }

    return -1;  // If end is unreachable
}
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    
cout << "~" << "\n";
}
}

// } Driver Code Ends