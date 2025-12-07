class Solution {
  public:
   void bfs( vector<vector<int>>adj,  vector<int>&ans,int src){
       priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

       pq.push({0,src});
       ans[src] = 0;
       while(!pq.empty()){
           int node = pq.top().second;
           int dist = pq.top().first;
           pq.pop();
           for(auto it: adj[node]){
               if(ans[it] > ans[node] + 1){
                   pq.push({ans[node]+1,it});
                   ans[it] = ans[node]+1;
               }
           }
       }
   }
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {
        // code here
        
        
        vector<int>ans(V,INT_MAX);
        vector<vector<int>>adj(V);
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        bfs(adj,ans,src);
        for(int i=0;i < V; i++){
            if(ans[i] == INT_MAX) ans[i] =-1;
        }
        return ans;
    }
};
