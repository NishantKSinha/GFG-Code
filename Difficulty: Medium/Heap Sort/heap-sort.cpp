//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// The functions should be written in a way that array become sorted
// in increasing order when heapSort() is called.
   // Function to heapify a subtree rooted at index i.
    // n is the size of the heap.
    void heapify(vector<int>& arr, int n, int i) {
        int largest = i;         // Initialize largest as root.
        int left = 2 * i + 1;    // Left child.
        int right = 2 * i + 2;   // Right child.

        // If the left child is larger than the root.
        if (left < n && arr[left] > arr[largest]) {
            largest = left;
        }

        // If the right child is larger than the largest so far.
        if (right < n && arr[right] > arr[largest]) {
            largest = right;
        }

        // If the largest is not the root.
        if (largest != i) {
            swap(arr[i], arr[largest]);

            // Recursively heapify the affected subtree.
            heapify(arr, n, largest);
        }
    }
    
     // Function to build a max heap.
    void buildHeap(vector<int>& arr, int n) {
        // Start from the last non-leaf node and move upwards.
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(arr, n, i);
        }
    }

class Solution {
  public:
    // Function to sort an array using Heap Sort.
    
        // code here
          // Function to sort an array using Heap Sort.
    void heapSort(vector<int>& arr) {
        int n = arr.size();

        // Step 1: Build a max heap.
        buildHeap(arr, n);

        // Step 2: Extract elements from the heap.
        for (int i = n - 1; i > 0; i--) {
            // Swap the first (largest) element with the last element.
            swap(arr[0], arr[i]);

            // Reduce the size of the heap and maintain the heap property.
            heapify(arr, i, 0);
        }
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        obj.heapSort(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        // cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends