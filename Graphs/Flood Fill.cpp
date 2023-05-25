class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int startColor = image[sr][sc]; // store the starting color

        if(startColor == color)
            return image;

        image[sr][sc] = color;
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0)); //visited matrix

       vis[sr][sc] = 1;
        q.push({sr,sc});

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            int delrow[] = {-1, 0, 1, 0};
            int delcol[] = {0, 1, 0, -1};
            for(int i=0; i<4; i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == startColor && !vis[nrow][ncol]){
                    image[nrow][ncol] = color;
                    vis[nrow][ncol] = 1;
                    q.push({nrow,ncol});
                }
            }
        }
        return image;
    }
};
