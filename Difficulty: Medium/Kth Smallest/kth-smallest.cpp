// User function template for C++

class Solution {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        priority_queue<int,vector<int>,greater<int>>pq;
        
        for(int i=0; i < arr.size();i++){
            pq.push(arr[i]);
        }
        
        int cnt = k-1;
        while(cnt != 0) {
            pq.pop();
            cnt--;
        }
        
        return pq.top();
    }
};