class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        int sum =0;
        int ans =0;
        unordered_map<int,int>mpp;
        for(int i=0; i < arr.size();i++){
            sum += arr[i];
            if(sum == k) ans = max(ans,i+1);
            if(mpp.find(sum-k) != mpp.end()){
                ans = max(ans,i - mpp[sum-k]);
            }
             if(mpp.find(sum) == mpp.end()) mpp[sum]=i;
        }
        return ans;
    }
};