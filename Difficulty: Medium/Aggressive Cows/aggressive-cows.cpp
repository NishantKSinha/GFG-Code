class Solution {
  public:
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        int l =1 , h = *max_element(stalls.begin(),stalls.end());
        int ans =INT_MIN;
        sort(stalls.begin(),stalls.end());
        while(l <= h){
            int mid = (l+h)/2;
            int cnt =1;
             int no = stalls[0];
            for(int i=1 ; i < stalls.size();i++){
               
                if(stalls[i] - no >= mid){
                    no = stalls[i];
                    cnt++;
                }
              
            }
            if(cnt >= k){
                ans = max(ans,mid);
                l = mid +1;
            }
            else h=mid-1;
        }
        return ans;
    }
};