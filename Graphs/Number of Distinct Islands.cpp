class Solution {
  private:
  void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<int>>& grid, vector<pair<int, int>>& vec,
  int row0, int col0){
      vis[row][col] = 1;
      vec.push_back({row - row0, col - col0}); //subtracting the coordinates from base coord to make it same
      int n = grid.size();
      int m = grid[0].size();
      
       //traversing all four directions of the selected cell
	   int drow[] = {-1, 0, 1, 0};
	   int dcol[] = {0, 1, 0, -1};
	        
	   for(int i=0; i<4; i++){
	       int nrow = row + drow[i];
	       int ncol = col + dcol[i];
	        
	   if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == 1){
	       dfs(nrow, ncol, vis, grid, vec, row0, col0);
	   }
  }
}
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
       int n = grid.size();
       int m = grid[0].size();
       vector<vector<int>>vis(n, vector<int>(m,0)); //n*m
       set<vector<pair<int, int>>> st; //to store unique paths
       
       for(int i=0; i<n; i++){
           for(int j=0; j<m; j++){
               if(!vis[i][j] && grid[i][j] == 1){
                   vector<pair<int, int>> vec;
                   dfs(i, j, vis, grid, vec, i, j); //i,j again as they are used as base row and base col (to subtract from)
                   st.insert(vec);
               }
           }
       }
       return st.size();
    }
};
//TC = O(n*m + log(n*m) + n*m) ; log(n*m) due to insertion into set
//SC - O(n*m)
