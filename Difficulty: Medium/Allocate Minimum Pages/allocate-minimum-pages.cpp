class Solution {
  public:
    int findPages(vector<int> &arr, int k) {
        // code here
        int h =accumulate(arr.begin(), arr.end(), 0);
        if(arr.size() < k) return -1;
        int l = *max_element(arr.begin(), arr.end());

        int ans = INT_MAX;
        while(l <= h){
            int mid= (l+h)/2;
            int sum=0;
            int cnt =1;
            int i=0;
            while( i < arr.size()){
                sum += arr[i];
                if(sum > mid){
                    cnt++;
                    sum =arr[i];
                    i++;
                }
                else i++;
            }
            if(cnt <= k ){
                ans = min(ans,mid);
                h= mid-1;
            }
            else l =mid+1;
        }
        return ans;
        
    }
};