class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        // Code here
        vector<int>ans;
        queue<int>q;
        vector<int>vis(adj.size(),0);
        
        q.push(0);
        vis[0] = 1;
        
        while(!q.empty()){
            int val = q.front();
            ans.push_back(val);
           
            q.pop();
            
            for(auto it : adj[val]){
                
                if(vis[it] != 1){
                    q.push(it);
                    vis[it] = 1;
                }
            }
        }
        return ans;
    }
};