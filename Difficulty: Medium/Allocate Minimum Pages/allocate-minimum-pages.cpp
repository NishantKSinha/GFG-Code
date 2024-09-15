//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template in C++

class Solution {
  public:
     long long  countStudents(int arr[], int pages,int n) {
     //size of array.
    int students = 1;
    long long pagesStudent = 0;
    for (int i = 0; i < n; i++) {
        if (pagesStudent + arr[i] <= pages) {
            //add pages to current student
            pagesStudent += arr[i];
        }
        else {
            //add pages to next student
            students++;
            pagesStudent = arr[i];
        }
    }
    return students;
}
    // Function to find minimum number of pages.
    long long findPages(int n, int arr[], int m) {
        // code here
    
    //book allocation impossible:
    if (m > n) return -1;
    
    int sum = 0;
    for (int i = 0; i < n; ++i) {
    sum += arr[i];
      }


    long long  high = sum;
    int max_val = arr[0];
     for (int i = 1; i < n; ++i) {
          if (arr[i] > max_val) {
        max_val = arr[i];
        }
      }long long  low = max_val;
   
    while (low <= high) {
        long long  mid = (low + high) / 2;
        long long  students = countStudents(arr, mid, n) ;
        if (students > m) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
            
        }
    }
    return low;  //else we can directly return low 
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        int m;
        cin >> m;
        Solution ob;
        cout << ob.findPages(n, A, m) << endl;
    }
    return 0;
}

// } Driver Code Ends