class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
                         
        //edge case
       if(source.first == destination.first && source.second == destination.second)
            return 0;
            
       queue<pair<int, pair<int, int>>> q; //to store {dist, {row, col}}
       int n = grid.size();
       int m = grid[0].size();
       vector<vector<int>> dist(n, vector<int>(m, 1e9)); //declare dist array of size n*m and mark all places as 1e9
       dist[source.first][source.second] = 0; //mark the coordinates of source as 0 in dist array
       q.push({0, {source.first, source.second}}); //push the {dist, {source row, source col}} in the queue
       
       int drow[] = {-1, 0, 1, 0};
       int dcol[] = {0, 1, 0, -1};
       
       while(!q.empty()){
           auto it = q.front();
           q.pop();
           
           int d = it.first;
           int r = it.second.first;
           int c = it.second.second;
           
           for(int i=0; i<4; i++){
               int nrow = r + drow[i];//new row formed after moving in a particular direction
               int ncol = c + dcol[i]; //new col formed after moving in a particular direction
               
               if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 && 1 + d < dist[nrow][ncol]){ //last cond-> means checking that after moving in a direction the total dist travelled < dist already stored 
                    dist[nrow][ncol] = 1 + d;
                    //check if we have reached the destination
                    if(nrow == destination.first && ncol == destination.second)  return 1 + d;
                    
                    q.push({1 + d, {nrow, ncol}});
           }
       }
    }
    return -1;
  }
};
