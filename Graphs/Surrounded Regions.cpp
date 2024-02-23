//main observation is that we should start from the boundaries, apply DFS and see which of them are O's as well as O's 
//connected to them, and all those will not be flipped to X, rest all the O's which are completely surrounded
//by X's (on all 4 sides) will be marked X.

class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& board, vector<int> delrow, vector<int> delcol){
        vis[row][col] = 1;
        int n = board.size();
        int m = board[0].size();

        //now check for top, right, left, bottom
        for(int i=0; i<4; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0 && board[nrow][ncol] == 'O'){
                dfs(nrow, ncol, vis, board, delrow, delcol);
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<int> delrow = {-1, 0, 1, 0};
        vector<int> delcol = {0, 1, 0, -1};

        vector<vector<int>> vis(n, vector<int>(m, 0));

        //checking for 1st and last rows
        for(int j=0; j<m; j++){

            //1st row
            if(vis[0][j] == 0 && board[0][j] == 'O'){
                dfs(0, j, vis, board, delrow, delcol);
            }

            //last row
            if(vis[n - 1][j] == 0 && board[n - 1][j] == 'O'){
                dfs(n - 1, j, vis, board, delrow, delcol);
            }
        }

        //checking for 1st and last columns
        for(int i=0; i<n; i++){

            //1st col
            if(vis[i][0] == 0 && board[i][0] == 'O'){
                dfs(i, 0, vis, board, delrow, delcol);
            }

            //last col
            if(vis[i][m - 1] == 0 && board[i][m - 1] == 'O'){
                dfs(i, m - 1, vis, board, delrow, delcol);
            }
        }

        //now all the nodes which are still O and have not been visited will be marked X
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(vis[i][j] == 0 && board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
};

//TC - O(n * m)
//SC - O(n * m)
