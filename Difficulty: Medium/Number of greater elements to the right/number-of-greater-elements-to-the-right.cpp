// User function Template for C++

class Solution {
  public:

    vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices) {
        // write your code here
        vector<int>ans(queries);
        for(int i =0 ; i < indices.size();i++){
            int idx = indices[i];
            stack<int>st;
            for(int j = idx+1 ; j < n; j++){
                if(arr[j] > arr[idx]) st.push(arr[j]);
            }
            ans[i] = st.size();
        }
        return ans;
    }
};