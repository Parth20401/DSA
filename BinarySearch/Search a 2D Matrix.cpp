class Solution {
public:
    bool binarySearchinRow(vector<int>& row, int target){
        int left = 0;
        int right = row.size() - 1;

        while(left <= right){
            int mid = left + (right - left)/2;
            if(row[mid] == target)
                return true;
            else if(row[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        for(auto i : matrix){
            //checking if target is in specified range
            if(target >= i[0] && target <= i[n - 1]){
                if(binarySearchinRow(i, target)){
                    return true;
                }
            }
        }
        return false;
    }
};

//Tc - O(m * log n)
//SC - O(1)
