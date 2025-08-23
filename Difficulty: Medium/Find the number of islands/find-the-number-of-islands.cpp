class Solution {
  public:
    void dfs(vector<vector<char>>& grid, vector<vector<int>>&vis,int i , int j){
        vis[i][j] =1;
        int n= grid.size();
        int m= grid[0].size();
        
       int dr[] = {-1, +1, 0, 0, -1, -1, +1, +1};
       int dc[] = {0, 0, -1, +1, -1, +1, -1, +1};
       
       for(int k=0 ;k <8;k++){
           int newr = dr[k] +i;
           int newc = dc[k] + j;
           
           if(newr >=0 && newc >=0 && newr <n && newc < m && vis[newr][newc] == 0 && grid[newr][newc] == 'L'){
               dfs(grid,vis,newr,newc);
           }
       }
    }
    int countIslands(vector<vector<char>>& grid) {
        // Code here
        int cnt =0;
        int n= grid.size();
        int m= grid[0].size();
        
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        for(int i=0 ;i <n;i++){
            for(int j =0 ; j <m ;j++){
                if(grid[i][j] == 'W') vis[i][j] =1;
                
                else if(grid[i][j] == 'L' && vis[i][j] == 0){
                    cnt++;
                    dfs(grid,vis,i,j);
                }
            }
        }
        return cnt;
    }
};