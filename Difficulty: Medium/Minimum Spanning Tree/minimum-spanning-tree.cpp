class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int,int>>>adj(V);
        for(auto it :edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        
        vector<int>vis(V,0);
       priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
       
       pq.push({0,0});
       int sum =0;
       
       while(!pq.empty()){
           int dist = pq.top().first;
           int node = pq.top().second;
           pq.pop();
           if(vis[node] == 0){
               vis[node] = 1;
               sum = sum + dist;
           }
           
           for(auto it : adj[node]){
               if(vis[it.first] == 0 ) pq.push({it.second , it.first});
           }
       }
       return sum;
    }
};