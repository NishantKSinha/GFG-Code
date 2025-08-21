class Solution {
  public:
  
   bool dfs( vector<int>&vis ,int start,vector<vector<int>>&adj,unordered_map<int,int>&mpp){
       
       
       vis[start] =1;
       
      
           for(auto it : adj[start]){
               
               if(vis[it] != 1){
                   mpp[it] = start;
                   if(dfs(vis, it, adj,mpp)) return true;
                 
                 
                 
               }
               else if(vis[it] == 1  && mpp[start] != it){
                   return true;
               }
            
            }
       return false;
       
   }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        
        vector<vector<int>>adj(V);
        
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int>vis(V,0);
        unordered_map<int,int>mpp;
        
        for(int i =0 ; i < V;i++){
            if(vis[i] != 1){
                bool ans = dfs(vis,i,adj,mpp);
                if(ans == true) return true;
            }
        }
        return false;
    }
};