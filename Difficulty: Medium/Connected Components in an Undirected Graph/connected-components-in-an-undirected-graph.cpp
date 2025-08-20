class Solution {
  public:
   void bfs(int start, vector<int>& ans, vector<int>& vis, vector<vector<int>>& adj) {
       queue<int> q;
       q.push(start);
       vis[start] = 1;
       ans.push_back(start);

       while (!q.empty()) {
           int node = q.front(); q.pop();
           for (int nbr : adj[node]) {
               if (!vis[nbr]) {
                   q.push(nbr);
                   ans.push_back(nbr);
                   vis[nbr] = 1;
               }
           }
       }
   }

   vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
       vector<vector<int>> adj(V);
       for (auto &e : edges) {
           adj[e[0]].push_back(e[1]);
           adj[e[1]].push_back(e[0]);
       }

       vector<vector<int>> res;
       vector<int> vis(V, 0);

       for (int i = 0; i < V; i++) {
           if (!vis[i]) {
               vector<int> ans;
               bfs(i, ans, vis, adj);
               res.push_back(ans);
           }
       }
       return res;
   }
};
