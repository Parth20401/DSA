class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size() - 1;
        vector<vector<int>> temp(matrix.size(), vector<int>(matrix.size(), 0)); //temp has the same size as matrix
        
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                temp[i][j] = matrix[n - j][i];
            }
        }

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                matrix[i][j] = temp[i][j];
            }
        }
    }
};
