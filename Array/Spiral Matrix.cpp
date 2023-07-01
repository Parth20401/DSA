class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int left = 0, right = m - 1, top = 0, bottom = n - 1;
        int direction = 1;
        vector<int> v;

        while(left <= right && top <= bottom){
            //first we go to right
            if(direction == 1){
                for(int i=left; i<=right; i++)  v.push_back(matrix[top][i]);
                direction = 2;
                top++; 
            }

            //now go down
           else if(direction == 2){
                for(int i=top; i<=bottom; i++)  v.push_back(matrix[i][right]);
                direction = 3;
                right--;
            }

            //now go right to left
            else if(direction == 3){
                for(int i=right; i>=left; i--)  v.push_back(matrix[bottom][i]);
                direction = 4;
                bottom--;
            }

            //go from bottom to up
            else if(direction == 4){
                for(int i=bottom; i>=top; i--)  v.push_back(matrix[i][left]);
                direction = 1; //again make direction 1 to start the spiral
                left++;
            }
        }
        return v;
    }
};
