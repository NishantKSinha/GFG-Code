// User function Template for C++
class Solution {
  public:
   void bfs(  vector<vector<pair<int,int>>>adj,  vector<int>&ans,int src){
       priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

       pq.push({0,src});
       ans[src] = 0;
       while(!pq.empty()){
           int node = pq.top().second;
           int dist = pq.top().first;
           pq.pop();
           for(auto it: adj[node]){
               if(ans[it.first] > ans[node] + it.second){
                   pq.push({ans[node]+it.second,it.first});
                   ans[it.first] = ans[node]+it.second;
               }
           }
       }
   }
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
          vector<int>ans(V,INT_MAX);
        vector<vector<pair<int,int>>>adj(V);
        for(auto it : edges){
            adj[it[0]].push_back({it[1],it[2]});
        }
        bfs(adj,ans,0);
        for(int i=0;i < V; i++){
            if(ans[i] == INT_MAX) ans[i] =-1;
        }
        return ans;
    }
};
