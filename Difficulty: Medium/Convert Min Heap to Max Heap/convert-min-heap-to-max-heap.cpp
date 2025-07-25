// User function Template for C++

class Solution {
  public:
    void maxheapify(int idx,vector<int> &arr, int N){
        int largest = idx;
        int left = 2*idx+1 ,right = 2*idx+2;
         if(left < N && arr[left] > arr[largest]) largest = left;
         if(right < N && arr[right] > arr[largest]) largest = right;
         
         if(largest != idx){
             swap(arr[largest],arr[idx]);
             maxheapify(largest,arr,N);
         }
    }
    void convertMinToMaxHeap(vector<int> &arr, int N) {
        for(int i =N-1; i >= 0;i--){
            maxheapify(i,arr,N);
        }
    }
};
