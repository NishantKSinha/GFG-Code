//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
    bool detect(int src ,vector<vector<int>>& adj,int vis[] ){
        vis[src] = 1;
        queue<pair<int,int>>q;
        q.push({src,-1});//we put -1 bcz src has not any parent
        
        while(!q.empty()){
            int parent = q.front().second;
            int node = q.front().first;
            
            q.pop();
            
            for(auto adjacentNode : adj[node]){
                if(!vis[adjacentNode]){
                    vis[adjacentNode]=1;
                    q.push({adjacentNode,node});
                }
                else if(vis[adjacentNode] == 1 && parent != adjacentNode) return true;
            }
        }
        return false;
        
    }
    bool isCycle(vector<vector<int>>& adj) {
        // Code here
        int vis[adj.size()] = {0};
        
        //this for loop is because we have to consider connected component graph too
        //otherwise we will also write directly src = 0 and then traverse or iterate-- 
        //--if we dont have to consider connected component
        
        for(int i = 0 ; i < adj.size() ;i++){
            if(!vis[i]){
                if(detect(i , adj , vis)== true) return 1;
            }
        }
        return 0;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends