class Solution {
  private:
  void bfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>> grid){
      int n = grid.size();
      int m = grid[0].size();
      vis[row][col] = 1;
      queue<pair<int,int>> q;
      q.push({row,col});
      
      while(!q.empty()){
          int row = q.front().first;
          int col = q.front().second;
          q.pop();
          
         //traverse the neighbours and mark them if it is land
         //two loops for finding out new row and new col
         for(int delrow=-1; delrow<=1; delrow++){
             for(int delcol=-1; delcol<=1; delcol++){
                 int nrow = row + delrow;
                 int ncol = col + delcol;
                 if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == '1' && !vis[nrow][ncol]){
                     vis[nrow][ncol] = 1; //marked as visited
                     q.push({nrow,ncol});
                 }
             }
         }
      }
  }
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
       int n = grid.size();
       int m = grid[0].size();
       vector<vector<int>> vis(n,vector<int>(m, 0)); // initializes the 2D vector vis with n rows, each row being a vector of m integers, all initialized to 0.
       int cnt = 0;
       for(int row=0; row<n; row++){
           for(int col=0; col<m; col++){
               if(!vis[row][col] && grid[row][col] == '1'){
                   bfs(row, col, vis, grid); 
                   cnt++;
               }
           }
       }
       return cnt;
    }
};
