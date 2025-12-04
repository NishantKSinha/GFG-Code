class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        // Code here
        vector<int>ans;
        queue<int>q;
        vector<int>vis(adj.size(),-1);
        q.push(0);
        vis[0] =1;
        ans.push_back(0);
        while(!q.empty()){
            int num = q.front();
            q.pop();
            for(auto it : adj[num]){
                if(vis[it] == -1){
                    vis[it] =1;
                    ans.push_back(it);
                    q.push(it);
                }
            }
        }
        return ans;
    }
};