class Solution {
  public:
     void bfs(vector<vector<pair<int,int>>>adj,  vector<int>&ans,int src,vector<int>&parent){
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
                   parent[it.first] = node;
               }
           }
       }
   }
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
          vector<int>ans(n+1,INT_MAX);
             vector<int>parent(n+1,-1);
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto it : edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        bfs(adj,ans,1,parent);
         if(ans[n] == INT_MAX) return {-1};
       vector<int>res;
       int i = n;
       while(i != -1){
           res.push_back(i);
           i = parent[i];
       }
       reverse(res.begin(),res.end());
       res.insert(res.begin(),ans[n]);
       return res;
    }
};