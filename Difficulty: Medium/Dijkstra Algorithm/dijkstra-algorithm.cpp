// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
          vector<vector<pair<int,int>>> adj(V);
         
        for(auto it: edges){
            adj[it[0]].push_back({it[1],it[2]});
        }
        
         queue<pair<int,int>>q;
         vector<int>ans(adj.size(),INT_MAX);
        q.push({src,0});
        ans[src] =0;
        
        while(!q.empty()){
            int dist = q.front().second;
            int val = q.front().first;
            q.pop();
            
            for(auto it: adj[val]){
                if(ans[it.first] > dist+it.second){
                    q.push({it.first,dist+it.second});
                    ans[it.first] = dist+it.second;
                }
            }
            
        }
        
        for(int i=0 ; i < ans.size();i++){
            if(ans[i] == INT_MAX) ans[i] =-1;
        }
        
        return ans;
        
    }
};