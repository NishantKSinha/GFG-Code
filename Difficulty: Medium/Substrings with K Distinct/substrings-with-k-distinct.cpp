class Solution {
  public:
  int find(string &s , int k){
      if (k <= 0) return 0;
        int i = 0, j = 0, ans = 0;
        int freq[26] = {0};
        int distinct = 0;

        while (j < s.size()) {
            if (freq[s[j] - 'a'] == 0) distinct++;
            freq[s[j] - 'a']++;

            while (distinct > k) {
                freq[s[i] - 'a']--;
                if (freq[s[i] - 'a'] == 0) distinct--;
                i++;
            }

            ans += (j - i + 1);
            j++;
        }

        return ans;
  }
    int countSubstr(string& s, int k) {
        // code here.
        int cnt1 = find(s,k);
        int cnt2 = find(s,k-1);
        return cnt1- cnt2;
    }
};