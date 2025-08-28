class Solution {
  public:
   void bfs(vector<int>& indegree, vector<vector<int>>& adj, queue<int>& q, vector<int>& ans){
        while(!q.empty()){
            int val = q.front();
            ans.push_back(val);
            q.pop();
            
            for(auto it: adj[val]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
    }

    string findOrder(vector<string> &words) {
        unordered_set<char> unique_letters;
        for (auto &word : words) {
            for (char c : word) {
                unique_letters.insert(c);
            }
        }
        
        vector<vector<int>> adj(26);
        vector<int> indegree(26,0);
        
        // build graph
        for(int i=0 ; i < (int)words.size()-1;i++){
            string str1 = words[i];
            string str2 = words[i+1];
            
            // prefix check: invalid case
            if(str1.size() > str2.size() && str1.substr(0, str2.size()) == str2)
                return "";  // invalid dictionary
            
            int len = min(str1.size(), str2.size());
            for(int j=0 ; j < len;j++){
                if(str1[j] != str2[j]) {
                    adj[str1[j]-'a'].push_back(str2[j]-'a');
                    indegree[str2[j]-'a']++;
                    break;
                }
            }
        }
        
        queue<int> q;
        for(char c : unique_letters){
            if(indegree[c - 'a'] == 0) q.push(c - 'a');
        }

        vector<int> ans;
        bfs(indegree, adj, q, ans);
       
        // check if all characters are covered (no cycle)
        if(ans.size() != unique_letters.size()) 
            return "";
        
        string res ="";
        for(int i =0 ; i < ans.size();i++){
            res += char('a' + ans[i]);  
        }
        return res;
    }
};
