class Solution {
  public:
   bool dfs( vector<int>&vis ,vector<vector<int>> &adj,int i, vector<int>&pathvis){
       vis[i] =1;
    pathvis[i] =1;
           
           for(auto it : adj[i]){
               if(vis[it] == 0 ){
                   if(dfs(vis,adj,it,pathvis) == true) return true;
               }
                else if(vis[it] ==1 && pathvis[it] ==1){
                    return true;
                }
           }
       pathvis[i] =0;    // while returning path vis ==0
       return false;
   }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> adj(V);
       for (auto &e : edges) {
           adj[e[0]].push_back(e[1]);
       }
        
        vector<int>vis(V,0);
        vector<int>pathvis(V,0);
      
        
        for(int i=0;i < V;i++){
            if(vis[i] == 0){
               if(dfs(vis,adj,i,pathvis) == true) return true;
            }
        }
        return false;
    }
};