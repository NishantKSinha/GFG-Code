class Solution {
  public:
    void  bfs(vector<vector<int>>&vis,int r ,int c , vector<vector<char>>&grid){
      queue<pair<int,int>>dq;
      dq.push({r,c});
      int dr[] = {0,0,-1,1,-1, -1, +1, +1};
      int dc[] = {-1,1,0,0,-1,1,-1,1};
      vis[r][c] = 1;
      while(!dq.empty()){
          int kr = dq.front().first;
          int kc = dq.front().second;
          dq.pop();
          for(int k = 0 ; k <8;k++){
            int nr = kr + dr[k];
            int nc = kc + dc[k];
            if(nr >= 0 && nc >=0 && nr <grid.size() && nc < grid[0].size() && vis[nr][nc] ==0 && grid[nr][nc] == 'L'){
                 vis[nr][nc] =1;
               
                 dq.push({nr,nc});
            }
          }
      }
   }
    int countIslands(vector<vector<char>>& grid) {
        // Code here
         vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),0));
        int cnt =0;
        for(int i =0 ; i < grid.size();i++){
            for(int j=0 ; j < grid[0].size();j++){
                
                    if(grid[i][j] == 'L' && vis[i][j] == 0){
                        cnt++;
                        bfs(vis,i,j,grid);
                    }
                }
            }
        
        return cnt;
    }
};