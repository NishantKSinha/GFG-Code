class Solution {
  public:
    int celebrity(vector<vector<int> >& mat) {
        // code here
        int ans =-1;
        int cnt1 =0;
        for(int j =0 ;j < mat[0].size();j++){
            int cnt =0;
            for(int i = 0 ;i < mat.size();i++){
                if(mat[i][j] == 1) cnt++;
            }
             if(cnt == mat.size()){
                     cnt1++;
                     ans =j;
                }
        }
        
        if(cnt1 == 1) {
            int cnt =0;
            for(int j = 0 ; j < mat[0].size();j++){
                if(mat[ans][j] == 1) cnt++;
            }
            if(cnt == 1) return ans ;
        }
        return -1;
    }
};