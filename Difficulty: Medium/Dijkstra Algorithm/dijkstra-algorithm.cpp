//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User Function Template
class Solution {
  public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex src.
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        // Code here
        int n = adj.size();
         
        //priroity queue min heap in pair of dist,node we are declaring
        //set are also use instead of priority queue
        // set stores the nodes in ascending order of the distances see soln article
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq; 
        
        vector<int>dist(n,1e9),parent(n);
        for(int i= 0 ;i< n;i++)parent[i] = i;
        
        dist[src] = 0 ;
        pq.push({src,0});
        //dijisktra
        while(!pq.empty()){
            int node = pq.top().first;
            int dis = pq.top().second;
            pq.pop();
            
            for(auto it:adj[node]){
                int adjnode = it.first;
                int ewt = it.second;
                
                if(dis + ewt < dist[adjnode]){
                    dist[adjnode] = dis + ewt;
                    pq.push({adjnode,dist[adjnode]});
                    parent[adjnode]=node;
                }
            }
        }
        return dist;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<pair<int, int>>> adj(V);
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            pair<int, int> t1 = {v, w}, t2 = {u, w};
            adj[u].push_back(t1);
            adj[v].push_back(t2);
        }
        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.dijkstra(adj, src);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends