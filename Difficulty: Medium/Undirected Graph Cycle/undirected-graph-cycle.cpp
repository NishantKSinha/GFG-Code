class Solution {
  public:
  
   bool bfs( vector<int>&vis ,int start,vector<vector<int>>adj,unordered_map<int,int>&mpp){
       
       queue<int>q;
       q.push(start);
       vis[start] =1;
       
       while(!q.empty()){
           int val = q.front();
           q.pop();
           
           for(auto it : adj[val]){
               
               if(vis[it] != 1){
                   vis[it] =1;
                   q.push(it);
                   mpp[it] = val;
               }
               else if(vis[it] == 1  && mpp[val] != it){
                   return true;
               }
            
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
                bool ans = bfs(vis,i,adj,mpp);
                if(ans == true) return true;
            }
        }
        return false;
    }
};