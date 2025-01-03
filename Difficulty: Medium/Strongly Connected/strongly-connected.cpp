//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Position this line where user code will be pasted.
class Solution {
  private:
    void dfs(int node, vector<int>& vis, vector<vector<int>>& adj, stack<int>& st) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, vis, adj, st);
            }
        }
        st.push(node);
    }

    void dfs3(int node, vector<int>& vis, vector<vector<int>>& adjT) {
        vis[node] = 1;
        for (auto it : adjT[node]) {
            if (!vis[it]) {
                dfs3(it, vis, adjT);
            }
        }
    }

  public:
    int kosaraju(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> vis(n, 0);
        stack<int> st;

        // Step 1: Perform DFS to get finish times
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, vis, adj, st);
            }
        }

        // Step 2: Reverse the graph
        vector<vector<int>> adjT(n);
        for (int i = 0; i < n; i++) {
            for (auto it : adj[i]) {
                adjT[it].push_back(i);
            }
        }

        // Step 3: Perform DFS on the reversed graph
        fill(vis.begin(), vis.end(), 0);
        int scc = 0;
        while (!st.empty()) {
            int node = st.top();
            st.pop();
            if (!vis[node]) {
                scc++;
                dfs3(node, vis, adjT);
            }
        }

        return scc;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.kosaraju(adj) << "\n";

        // cout << "~"
        //      << "\n";
    }

    return 0;
}

// } Driver Code Ends