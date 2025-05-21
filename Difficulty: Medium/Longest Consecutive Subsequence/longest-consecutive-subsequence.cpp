class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        // Your code here
        sort(arr.begin(),arr.end());
        int ans =1;
           int cnt = 1;
        int i = 0;
        while(i < arr.size()-1){
            while(arr[i] == arr[i+1]) i++;
            if(arr[i] + 1 == arr[i+1]){
                cnt++;
                ans = max(ans,cnt);
                i++;
            }
            else{
                i++;
                cnt=1;
            }
        }
        return ans;
    }
};