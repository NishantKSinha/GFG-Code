class Solution {
public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        vector<int> dis(V, 1e8);
        dis[src] = 0;

        // Relax all edges V-1 times
        for(int i = 0; i < V-1; i++) {
            for(auto it : edges) {
                int u = it[0];
                int v = it[1];
                int wt = it[2];

                // For directed edge u -> v
                if(dis[u] != 1e8 && dis[u] + wt < dis[v]) {
                    dis[v] = dis[u] + wt;
                }

                
               
            }
        }

        // Check for negative weight cycles
        for(auto it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            if(dis[u] != 1e8 && dis[u] + wt < dis[v]) {
                return {-1};  // negative cycle detected
            }
            
        }

        return dis;
    }
};
