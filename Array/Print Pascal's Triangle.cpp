class Solution {
public:
    vector<int> generateRow(int row){
        long long ans = 1;//long long to avoid overflow
        vector<int> ansRow;
        ansRow.push_back(1);
        for(int col=1; col<row; col++){
            ans = ans * (row - col);
            ans = ans / col;
            ansRow.push_back(ans);
        }
        return ansRow;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascalTriangle;
        for(int i=1; i<=numRows; i++){
            pascalTriangle.push_back(generateRow(i));
        }
        return pascalTriangle;
    }
};

//TC - O(N^2)
//SC - O(1)
