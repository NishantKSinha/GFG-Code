class Solution {
  public:
   int upperbound(vector<int>& arr, int x){//follow striver approach
        //tc == 2 * o(log n)==> 2 bcz one for upperbound find and another for lowerbound find 
         int i = 0 , j  = arr.size()-1;
        int ans =arr.size();
        while(i <= j){
            int mid  = (i+j)/2;
            if(arr[mid] > x){
                ans = mid;
                j = mid -1;
            }
            else{
                i = mid+1;
            }
        }
        return ans;
    }
    int lowerbound(vector<int>& arr, int x){
       int k = 0 , l  = arr.size()-1;
       int higher = arr.size();
        while(k <= l){
            int mid  = (k+l)/2;
            if(arr[mid] >= x){
                higher = min(higher,mid);
                l = mid -1;
            }
            else{
                k = mid+1;
            }
        }
      
        return higher;
    }
    int countFreq(vector<int>& arr, int target) {
        // code here
        int cnt1 = lowerbound(arr,target);
        int cnt2 = upperbound(arr,target);
        return cnt2-cnt1;
        
    }
};
