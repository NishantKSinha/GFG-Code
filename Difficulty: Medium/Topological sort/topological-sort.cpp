class Solution {
  public:
   
   void bfs(vector<vector<int>>& adj, vector<int>& indegree, queue<int>& q, vector<int>& ans) {
       while(!q.empty()) {
           int val = q.front();
           ans.push_back(val);
           q.pop();
           
           for(auto it : adj[val]) {
               indegree[it]--;
               if(indegree[it] == 0) {
                   q.push(it);
               }
           }
       }
   }
   
   vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        vector<int> indegree(V,0);
        
        // build graph + indegree
        for(auto &it: edges){
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }
       
        queue<int> q;
        for(int i = 0; i < V; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        vector<int> ans;
        bfs(adj, indegree, q, ans);
        
        return ans;
   }
};
