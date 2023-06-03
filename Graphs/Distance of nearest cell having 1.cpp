class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int n = grid.size();
	    int m = grid[0].size();
	    
	    vector<vector<int>>vis(n, vector<int>(m, 0)); //visited array
	    vector<vector<int>>dist(n, vector<int>(m, 0)); //stores dist of nearest cell having 1
	    queue<pair<pair<int, int>, int>> q; //{{row,column}, dist}
	    //pushing starting elements into queue
	    for(int i=0 ; i<n; i++){
	        for(int j=0; j<m; j++){
	            if(grid[i][j] == 1){  //or grid[i][j] == 0 for nearest 0
	                q.push({{i, j}, 0}); //push starting points into queue i.e, those cells constaining 1
	                vis[i][j] = 1;
	            }
	            else{
	                vis[i][j] = 0;
	            }
	        }
	    }
	    
	    while(!q.empty()){
	        int row = q.front().first.first;
	        int col = q.front().first.second;
	        int steps = q.front().second;
	        q.pop();
	        dist[row][col] = steps;
	        
	        //traversing all four directions of the selected cell
	        int drow[] = {-1, 0, 1, 0};
	        int dcol[] = {0, 1, 0, -1};
	        
	        for(int i=0; i<4; i++){
	            int nrow = row + drow[i];
	            int ncol = col + dcol[i];
	        
	        if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0){
	            q.push({{nrow, ncol}, steps + 1});//d + 1 bcos everytime new element pushed, it increases steps
	            vis[nrow][ncol] = 1;
	            }
	        }
	    }
	    return dist;
	} 
};
