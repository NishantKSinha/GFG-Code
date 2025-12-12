class Solution {
  public:
    int fun(vector<vector<int>>&dp, vector<vector<int>>&arr, int days, int take){
        if(days == 0){
            int maxi =0;
            for(int i=0 ; i <3; i++) {
                
                if(i != take )maxi = max(maxi, arr[0][i]);
            }
            dp[days][take] = maxi;
            return maxi;
        }
        if(dp[days][take] != -1) return dp[days][take];
        int maxi =0;
        for(int i=0; i < 3; i++){
            if(i != take){
                maxi = max(maxi ,  arr[days][i] + fun(dp,arr,days-1,i));
            }
        }
        return dp[days][take] = maxi;
    }
    int maximumPoints(vector<vector<int>>& arr) {
        // Code here
        int n = arr.size();
        int m = arr[0].size();
        vector<vector<int>>dp(n,vector<int>(4,-1));
        //3-> no select
        fun(dp,arr,n-1,3);
      
        return dp[n-1][3];
    }
};