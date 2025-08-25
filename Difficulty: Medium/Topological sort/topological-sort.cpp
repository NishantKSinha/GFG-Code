class Solution {
  public:
  
   void dfs(int i,vector<int>&vis,stack<int>&st, vector<vector<int>>&adj){
       vis[i] =1;
       
       
       for(auto it:adj[i]){
           if(vis[it] == 0){
               dfs(it,vis,st,adj);
           }
       }
       
       st.push(i);   //during returning 
   }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>>adj(V);
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
        }
        vector<int>vis(V,0);
        stack<int>st;
        vector<int>ans;
        
        for(int i=0 ; i < V; i++){
            if(vis[i] == 0){
                dfs(i,vis,st,adj);
            }
        }
        
        while(!st.empty()){
            int val= st.top();
            st.pop();
            ans.push_back(val);
        }
        return ans;
    }
};