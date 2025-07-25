
class Solution {
  public:
    bool isMaxHeap(int arr[], int n) {
        // Your code goes here
        for(int i =0; i <n ;i++){
            int left = 2*i +1;
            int right = 2*i + 2;
            if(left < n && arr[left] > arr[i] || right < n && arr[right] > arr[i] ){
                return 0;
            }
        }
        return 1;
    }
};