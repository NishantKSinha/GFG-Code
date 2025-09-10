// User function template for C++
class Solution {
public:
    void floydWarshall(vector<vector<int>> &mat) {
        int n = mat.size();
        int INF = 1e8;

        // Step 1: Diagonal = 0
        for (int i = 0; i < n; i++) {
            mat[i][i] = 0;
        }

        // Step 2: Floyd–Warshall relaxation
        for (int via = 0; via < n; via++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (mat[i][via] < INF && mat[via][j] < INF) {
                        mat[i][j] = min(mat[i][j], mat[i][via] + mat[via][j]);
                    }
                }
            }
        }

        // No need to convert back, since problem states 1e8 = no edge
    }
};
