//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    bool isMaxHeap(int arr[], int n)
    {
        // Your code goes here
        // Traverse all internal nodes
        for (int i = 0; i <= (n - 2) / 2; i++) {
            int left = 2 * i + 1;  // Index of the left child
            int right = 2 * i + 2; // Index of the right child

            // Check if the left child exists and violates the Max Heap property
            if (left < n && arr[i] < arr[left]) {
                return false;
            }

            // Check if the right child exists and violates the Max Heap property
            if (right < n && arr[i] < arr[right]) {
                return false;
            }
        }
        // If no violations, it is a Max Heap
        return true;
    }
};

//{ Driver Code Starts.
int main() {
    
    int t;
    cin >> t;
    while(t--)
    {
       int n;
       cin >> n;
       int a[4*n]={0};
       for(int i =0;i<n;i++){
           cin >> a[i];
       }
       Solution ob;
       cout<<ob.isMaxHeap(a, n)<<endl;
        
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends