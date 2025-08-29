class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // code here
        vector<int>ans(adj.size(),INT_MAX);
        queue<pair<int,int>>q;
        
        q.push({src,0});
        ans[src] =0;
        
        while(!q.empty()){
            int dist = q.front().second;
            int val = q.front().first;
            q.pop();
            
            for(auto it: adj[val]){
                if(ans[it] > dist+1){
                    q.push({it,dist+1});
                    ans[it] = dist+1;
                }
            }
            
        }
        
        for(int i=0 ; i < ans.size();i++){
            if(ans[i] == INT_MAX) ans[i] =-1;
        }
        
        return ans;
    }
};