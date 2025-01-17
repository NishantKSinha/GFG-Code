//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
 void maxheapify(vector<int>& arr, int N, int i) {
        int largest = i;         // Initialize largest as the root
        int left = 2 * i + 1;    // Left child
        int right = 2 * i + 2;   // Right child

        // Check if the left child is larger than the current largest
        if (left < N && arr[left] > arr[largest]) {
            largest = left;
        }

        // Check if the right child is larger than the current largest
        if (right < N && arr[right] > arr[largest]) {
            largest = right;
        }

        // If the largest is not the root, swap and continue heapifying
        if (largest != i) {
            swap(arr[i], arr[largest]);
            maxheapify(arr, N, largest);
        }
    }
    void convertMinToMaxHeap(vector<int> &arr, int N){
       // Start from the last non-leaf node and heapify each node.
        for (int i = N / 2 - 1; i >= 0; i--) {
            maxheapify(arr, N, i);
        }
    }
    
};


//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input

       int n; cin >> n;
       vector<int> vec(n);
       for(int i = 0;i<n;i++) cin >> vec[i];

        Solution obj;
        obj.convertMinToMaxHeap(vec,n);
        for(int i = 0;i<n;i++) cout << vec[i] << " ";
        cout << endl;
        

        
        // cout << "~\n";
    
cout << "~" << "\n";
}
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends