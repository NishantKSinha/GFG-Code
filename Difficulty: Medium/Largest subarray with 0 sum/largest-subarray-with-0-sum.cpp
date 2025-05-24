/*You are required to complete this function*/

class Solution {
  public:
    int maxLen(vector<int>& arr) {
        // code here
        int cnt = 0 ,sum = 0;
        unordered_map<int,int>mpp;
        for(int i =0 ; i < arr.size();i++){
            sum = sum + arr[i];
            if(sum == 0) cnt = max(cnt,i+1);
            int rem = sum - 0 ; //target =0
            if(mpp.find(rem) != mpp.end()){
                cnt = max(cnt,i-mpp[rem]);
            }
            if(mpp.find(sum) == mpp.end() ){ // to store only unique
                mpp[sum] = i;
            }
        }
        return cnt;
    }
};