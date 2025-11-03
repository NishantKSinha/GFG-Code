class Solution {
  public:
    int floorSqrt(int n) {
        // code here
        int l=1,h =n;
        int ans = -1;
        while(l <= h){
            int mid =(l+h)/2;
            if(mid * mid <= n ){
                ans = max(ans,mid);
                l = mid+1;
            }
            else{
                h =  mid-1;
            }
        }
        return ans;
    }
};