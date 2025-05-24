class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        unordered_map<int,int>mpp;
        for(int i = 0 ; i < arr.size();i++){
            mpp[arr[i]]++;
        }
        vector<int>ans;
        int a =-1,b=-1;
        for(auto it : mpp){
            if(it.second == 2) a = it.first;
        }
        for(int i = 1 ; i <= arr.size();i++){
            if(mpp.find(i) == mpp.end()) {
                b = i;
                break;
            }
        }
        return ans = {a,b};
    }
};