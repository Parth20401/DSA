class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>> q; //pair to store row and column
        int fresh = 0; //keep track of all fresh oranges

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 2)
                    q.push({i,j});
                if(grid[i][j] == 1)
                    fresh++;
            }
        }
        int drow[] = {-1, 0, 1, 0}; //to make change in rows
        int dcol[] = {0, 1, 0, -1};// to make change in col
        int ans = -1;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                pair<int,int> p = q.front();
                q.pop();

                for(int i=0; i<4; i++){
                    int r = p.first + drow[i];
                    int c = p.second + dcol[i];
                    if(r >= 0 && r<m && c >= 0 && c < n && grid[r][c] == 1){
                        grid[r][c] = 2;
                        q.push({r,c});
                        fresh--; // decrement by 1 foreach fresh orange that now is rotten
                    }
                }
            }
            ans ++; //incremented after each minute passes
        }
        if(fresh > 0) return -1; //means oranges are left
        if(ans == -1) return 0; //measn no oranges
        return ans;
    }
};
