//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    void shortestDistance(vector<vector<int>>& mat) {
        // Code here
        //in this -> question is saying we don't have to create new cost matrix we have
        //to do change in same matrix
        
        int n = mat.size();
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(mat[i][j] == -1 ){
                    mat[i][j] = 1e9;
                }
            
            if(i == j) mat[i][j] == 0 ;
            }
        }
        //algo
        for(int via = 0 ; via < n ; via++){
            for(int i = 0 ; i < n ; i++){
                for(int j = 0 ; j < n ; j++){
                    mat[i][j] = min(mat[i][j] , mat[i][via] + mat[via][j]);
                }
            }
        }
        
        /*for negative cycle check
            for(int i = 0 ; i<n;i++) -> if(mat[i][i] < 0) return -1 */
        
        
        for(int i = 0 ; i < n ; i++){ // changing the matrix to original form
            for(int j = 0 ; j < n ; j++){
                if(mat[i][j] == 1e9 ){
                    mat[i][j] = -1;
                }
            }
        }
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<int>> matrix(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }
        Solution obj;
        obj.shortestDistance(matrix);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends