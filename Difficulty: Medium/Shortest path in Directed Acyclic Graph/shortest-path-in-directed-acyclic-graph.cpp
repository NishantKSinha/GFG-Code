// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        
        vector<vector<pair<int,int>>> adj(V);  // n empty adjacency lists

         
        for(auto it: edges){
            adj[it[0]].push_back({it[1],it[2]});
        }
        
         queue<pair<int,int>>q;
         vector<int>ans(adj.size(),INT_MAX);
        q.push({0,0});
        ans[0] =0;
        
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
