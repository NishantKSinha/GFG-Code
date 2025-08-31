class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
         vector<vector<pair<int,int>>>adj(n+1);  //1-base indexing
         
        for(auto it : edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        
        vector<int>distance(n+1,INT_MAX);
        vector<int>parent(n+1,-1);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
         
        pq.push({0,1});  //dist,node
        distance[1] =0;
        
        while(!pq.empty()){
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto it: adj[node]){
                if(it.second+dist < distance[it.first]){
                    distance[it.first] = it.second+dist;
                    parent[it.first] = node;
                    pq.push({it.second+dist,it.first});
                }
            }
        }
        
         if(distance[n] == INT_MAX) return {-1}; //if destination not reachable
        
        vector<int>ans;
         
        int i = n;
        while(i != -1){
            ans.push_back(i);
            i = parent[i];
        }
        
        reverse(ans.begin(),ans.end());
        
        // insert distance at the front
ans.insert(ans.begin(), distance[n]);
        return ans;
    }
};